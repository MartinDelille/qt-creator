// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0+ OR GPL-3.0 WITH Qt-GPL-exception-1.0

#include "documentwatcher.h"

#include <coreplugin/editormanager/editormanager.h>

#include <texteditor/texteditor.h>

#include <QJsonDocument>

using namespace LanguageServerProtocol;
using namespace TextEditor;

namespace Copilot::Internal {

DocumentWatcher::DocumentWatcher(CopilotClient *client, TextDocument *textDocument)
    : m_client(client)
    , m_textDocument(textDocument)
{
    m_lastContentSize = m_textDocument->document()->characterCount(); //toPlainText().size();
    m_debounceTimer.setInterval(500);
    m_debounceTimer.setSingleShot(true);

    connect(textDocument, &TextDocument::contentsChanged, this, [this]() {
        if (!m_isEditing) {
            const int newSize = m_textDocument->document()->characterCount();
            if (m_lastContentSize < newSize) {
                m_debounceTimer.start();
            }
            m_lastContentSize = newSize;
        }
    });

    connect(&m_debounceTimer, &QTimer::timeout, this, [this]() { getSuggestion(); });
}

void DocumentWatcher::getSuggestion()
{
    auto editor = Core::EditorManager::instance()->activateEditorForDocument(m_textDocument);
    auto textEditorWidget = qobject_cast<TextEditor::TextEditorWidget *>(editor->widget());
    if (!editor || !textEditorWidget)
        return;

    auto cursor = textEditorWidget->multiTextCursor();
    if (cursor.hasMultipleCursors() || cursor.hasSelection())
        return;

    const int currentCursorPos = cursor.cursors().first().position();

    m_client->requestCompletion(
        m_textDocument->filePath(),
        m_client->documentVersion(m_textDocument->filePath()),
        Position(editor->currentLine() - 1, editor->currentColumn() - 1),
        [this, textEditorWidget, currentCursorPos](const GetCompletionRequest::Response &response) {
            if (response.error()) {
                qDebug() << "ERROR:" << *response.error();
                return;
            }

            const std::optional<GetCompletionResponse> result = response.result();
            QTC_ASSERT(result, return);

            const auto list = result->completions().toList();

            if (list.isEmpty())
                return;

            auto cursor = textEditorWidget->multiTextCursor();
            if (cursor.hasMultipleCursors() || cursor.hasSelection())
                return;
            if (cursor.cursors().first().position() != currentCursorPos)
                return;

            const auto firstCompletion = list.first();
            const QString content = firstCompletion.text().mid(
                firstCompletion.position().character());

            m_isEditing = true;
            textEditorWidget->insertSuggestion(content);
            m_isEditing = false;
            /*
            m_isEditing = true;
            const auto &block = m_textDocument->document()->findBlockByLineNumber(
                firstCompletion.position().line());
            m_textDocument->insertSuggestion(content, block);
            m_isEditing = false;
            */
        });
}

} // namespace Copilot::Internal
