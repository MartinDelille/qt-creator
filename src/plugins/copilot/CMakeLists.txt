add_qtc_plugin(Copilot
  SKIP_TRANSLATION
  PLUGIN_DEPENDS Core LanguageClient
  SOURCES
    authwidget.cpp authwidget.h
    copilotplugin.cpp copilotplugin.h
    copilotclient.cpp copilotclient.h
    copilotsettings.cpp copilotsettings.h
    copilotoptionspage.cpp copilotoptionspage.h
    copilotoptionspagewidget.cpp copilotoptionspagewidget.h
    documentwatcher.cpp documentwatcher.h
    requests/getcompletions.h
    requests/checkstatus.h
    requests/signout.h
    requests/signininitiate.h
    requests/signinconfirm.h
)
