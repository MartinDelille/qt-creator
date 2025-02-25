// Copyright (C) 2016 Jochen Becher
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#pragma once

#include <QtGlobal>

namespace ModelEditor {
namespace Constants {

const char MODEL_EDITOR_ID[] = "Editors.ModelEditor";
const char MODEL_EDITOR_DISPLAY_NAME[] = QT_TRANSLATE_NOOP("OpenWith::Editors", "Model Editor");

const char REMOVE_SELECTED_ELEMENTS[] = "ModelEditor.RemoveSelectedElements";
const char DELETE_SELECTED_ELEMENTS[] = "ModelEditor.DeleteSelectedElements";
const char OPEN_PARENT_DIAGRAM[] = "ModelEditor.OpenParentDiagram";
const char MENU_ID[] = "ModelEditor.Menu";
const char EXPORT_DIAGRAM[] = "ModelEditor.ExportDiagram";
const char EXPORT_SELECTED_ELEMENTS[] = "ModelEditor.ExportSelectedElements";
const char ACTION_ADD_PACKAGE[] = "ModelEditor.Action.AddPackage";
const char ACTION_ADD_COMPONENT[] = "ModelEditor.Action.AddComponent";
const char ACTION_ADD_CLASS[] = "ModelEditor.Action.AddClass";
const char ACTION_ADD_CANVAS_DIAGRAM[] = "ModelEditor.Action.AddCanvasDiagram";
const char ACTION_SYNC_BROWSER[] = "ModelEditor.Action.SynchronizeBrowser";

const char EXPLORER_GROUP_MODELING[] = "ModelEditor.ProjectFolder.Group.Modeling";
const char ACTION_EXPLORER_OPEN_DIAGRAM[] = "ModelEditor.Action.Explorer.OpenDiagram";

const char SHORTCUT_MODEL_EDITOR_EDIT_PROPERTIES[] =
        "ModelEditor.ModelEditor.Shortcut.EditProperties";
const char SHORTCUT_MODEL_EDITOR_EDIT_ITEM[] =
        "ModelEditor.ModelEditor.Shortcut.EditItem";

const char WIZARD_CATEGORY[] = "O.Model";
const char WIZARD_TR_CATEGORY[] = QT_TRANSLATE_NOOP("Modeling", "Modeling");
const char WIZARD_MODEL_ID[] = "SA.Model";

const char MIME_TYPE_MODEL[] = "text/vnd.qtcreator.model";

// Settings entries
const char SETTINGS_GROUP[] = "ModelEditorPlugin";
const char SETTINGS_RIGHT_SPLITTER[] = "RightSplitter";
const char SETTINGS_RIGHT_HORIZ_SPLITTER[] = "RightHorizSplitter";

} // namespace Constants
} // namespace ModelEditor
