// Phase 1: Loading  -------------------------------------------------------------
modded class LoadingScreen
{
    protected ImageWidget m_Background, m_TopShader, m_BottomShader, m_Mask, m_Logo;
    protected TextWidget m_LoadingMsg, m_Title;
    protected ProgressBarWidget m_ProgressLoading;

    void LoadingScreen(DayZGame game)
    {
        CuiLogger.Log("LoadingScreen.LoadingScreen() - Initializing loading layout");

        m_DayZGame = game;
        m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/loading/cui.loading.layout");

        CuiLogger.Log("LoadingScreen.LoadingScreen() - Widget root created");

        Class.CastTo(m_Background, m_WidgetRoot.FindAnyWidget("ImageBackground"));
        Class.CastTo(m_Logo, m_WidgetRoot.FindAnyWidget("Logo"));
        Class.CastTo(m_TopShader, m_WidgetRoot.FindAnyWidget("TopShader"));
        Class.CastTo(m_BottomShader, m_WidgetRoot.FindAnyWidget("BottomShader"));
        Class.CastTo(m_LoadingMsg, m_WidgetRoot.FindAnyWidget("LoadingMsg"));
        Class.CastTo(m_ProgressLoading, m_WidgetRoot.FindAnyWidget("LoadingBar"));
        Class.CastTo(m_Title, m_WidgetRoot.FindAnyWidget("Title"));

        if (m_TopShader) m_TopShader.SetColor(colorScheme.TopShader());
        if (m_BottomShader) m_BottomShader.SetColor(colorScheme.BottomShader());
        if (m_LoadingMsg) m_LoadingMsg.SetColor(colorScheme.LoadingMsg());
        if (m_LoadingMsg) m_LoadingMsg.SetText("GAME IS LOADING!");
        if (m_ProgressLoading) m_ProgressLoading.SetColor(colorScheme.Loadingbar());

        Branding.ApplyLogo(m_Logo);
        ProgressAsync.SetProgressData(m_ProgressLoading);
        ProgressAsync.SetUserData(m_Background);

        CuiLogger.Log("LoadingScreen.LoadingScreen() - Layout initialized");
    }

    override void Show()
    {
        CuiLogger.Log("LoadingScreen.Show() - Showing loading screen");
        if (m_Background) m_Background.LoadImageFile(0, loadscreens.GetRandomElement());
    }

    override void SetTitle(string title)
    {
        if (!m_Title)
        {
            m_Title = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("Title"));
            CuiLogger.Log("LoadingScreen.SetTitle() - Rebinding m_Title");
        }

        if (m_Title)
        {
            m_Title.SetText(title);
        }
        else
        {
            CuiLogger.Log("LoadingScreen.SetTitle() - m_Title is null");
        }
    }
}

// Phase 2: Logging In ------------------------------------------------------------
modded class LoginTimeBase extends LoginScreenBase
{
    protected ImageWidget m_Background, m_TopShader, m_BottomShader, m_ExitIcon, m_Logo;
    protected TextWidget m_LoadingMsg, m_ExitText;
    protected ProgressBarWidget m_ProgressLoading;

    override Widget Init()
    {
        CuiLogger.Log("LoginTimeBase.Init() - Creating logging in layout");

        layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/loading/cui.loggingIn.layout");

        CuiLogger.Log("LoginTimeBase.Init() - Layout created");

        m_Background = ImageWidget.Cast(layoutRoot.FindAnyWidget("ImageBackground"));
        m_Logo = ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"));
        m_TopShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
        m_BottomShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
        m_LoadingMsg = TextWidget.Cast(layoutRoot.FindAnyWidget("LoadingMsg"));
        m_ProgressLoading = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));

        m_btnLeave = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
        m_ExitText = TextWidget.Cast(layoutRoot.FindAnyWidget("ExitText"));
        m_ExitIcon = ImageWidget.Cast(layoutRoot.FindAnyWidget("Exit"));

        if (m_Background)
        {
            string bg = loadscreens.GetRandomElement();
            CuiLogger.Log("LoginTimeBase.Init() - Background selected: " + bg);
            m_Background.LoadImageFile(0, bg);
        }

        if (m_TopShader) m_TopShader.SetColor(colorScheme.TopShader());
        if (m_BottomShader) m_BottomShader.SetColor(colorScheme.BottomShader());
        if (m_LoadingMsg) m_LoadingMsg.SetColor(colorScheme.LoadingMsg());
        if (m_ProgressLoading) m_ProgressLoading.SetColor(colorScheme.Loadingbar());
        if (m_ExitIcon) m_ExitIcon.SetColor(colorScheme.Icons());

        Branding.ApplyLogo(m_Logo);

        return layoutRoot;
    }

    override bool OnMouseEnter(Widget w, int x, int y)
    {
        if (w == m_btnLeave)
        {
            CuiLogger.Log("LoginTimeBase.OnMouseEnter() - Hovered Leave Button");
            if (m_ExitText) m_ExitText.SetColor(colorScheme.ButtonHover());
            if (m_btnLeave) m_btnLeave.SetColor(UIColor.Transparent());
            return true;
        }
        return false;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        if (w == m_btnLeave)
        {
            CuiLogger.Log("LoginTimeBase.OnMouseLeave() - Left Leave Button");
            if (m_ExitText) m_ExitText.SetColor(colorScheme.PrimaryText());
            return true;
        }
        return false;
    }
}

// Phase 3: Prio Queue  -------------------------------------------------------------
modded class LoginQueueBase extends LoginScreenBase
{
    protected ImageWidget m_TopShader, m_BottomShader, m_ExitIcon, m_ShopIcon;
    protected TextWidget m_ExitText, m_PrioText;
    protected ProgressBarWidget m_ProgressLoading;
    protected ButtonWidget m_btnLeave, m_PrioQBtn;

    override Widget Init()
    {
        CuiLogger.Log("LoginQueueBase.Init() - Setting up Priority Queue UI");

        layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/loading/cui.priorityQueue.layout");
        CuiLogger.Log("LoginQueueBase.Init() - Layout created");

        m_HintPanel = new UiHintPanelLoading(layoutRoot.FindAnyWidget("hint_frame0"));
        m_txtPosition = TextWidget.Cast(layoutRoot.FindAnyWidget("LoadingMsg"));
        m_txtNote = TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));

        m_TopShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
        m_BottomShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
        m_ProgressLoading = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));

        m_btnLeave = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
        m_ExitText = TextWidget.Cast(layoutRoot.FindAnyWidget("ExitText"));
        m_ExitIcon = ImageWidget.Cast(layoutRoot.FindAnyWidget("Exit"));

        m_PrioQBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnPrioQ"));
        m_PrioText = TextWidget.Cast(layoutRoot.FindAnyWidget("PrioText"));
        m_ShopIcon = ImageWidget.Cast(layoutRoot.FindAnyWidget("shopIcon"));

        if (m_ExitIcon) m_ExitIcon.SetColor(colorScheme.Icons());
        if (m_ShopIcon) m_ShopIcon.SetColor(colorScheme.Icons());
        if (m_TopShader) m_TopShader.SetColor(colorScheme.TopShader());
        if (m_BottomShader) m_BottomShader.SetColor(colorScheme.BottomShader());
        if (m_ProgressLoading) m_ProgressLoading.SetColor(colorScheme.Loadingbar());

        if (CustomURL.PriorityQ == "#" || CustomURL.PriorityQ == "")
        {
            m_PrioQBtn.Show(false);
        }
        else
        {
            CuiLogger.Log("LoginQueueBase.Init() - Showing Priority Queue button");
            m_PrioQBtn.Show(true);
        }

        return layoutRoot;
    }

    override void Show()
    {
        CuiLogger.Log("LoginQueueBase.Show() - Displaying queue screen");
        if (!NoHints)
        {
            layoutRoot.Show(true);
            m_HintPanel = new UiHintPanelLoading(layoutRoot.FindAnyWidget("hint_frame0"));
        }
    }

    override void SetPosition(int position)
    {
        if (position != m_iPosition)
        {
            m_iPosition = position;
            if (m_txtPosition)
            {
                m_txtPosition.SetText("Position in Queue " + position.ToString());
                m_txtPosition.SetColor(colorScheme.LoadingMsg());
            }
            else
            {
                CuiLogger.Log("LoginQueueBase.SetPosition() - ERROR: m_txtPosition is null!");
            }
        }
    }

    override bool OnMouseEnter(Widget w, int x, int y)
    {
        if (w == m_btnLeave)
        {
            CuiLogger.Log("LoginQueueBase.OnMouseEnter() - Hovered Leave Button");
            if (m_ExitText) m_ExitText.SetColor(colorScheme.ButtonHover());
            if (m_btnLeave) m_btnLeave.SetColor(UIColor.Transparent());
            return true;
        }
        if (w == m_PrioQBtn)
        {
            CuiLogger.Log("LoginQueueBase.OnMouseEnter() - Hovered Prio Queue Button");
            if (m_PrioText) m_PrioText.SetColor(colorScheme.ButtonHover());
            if (m_PrioQBtn) m_PrioQBtn.SetColor(UIColor.Transparent());
            return true;
        }
        return false;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        if (w == m_btnLeave)
        {
            CuiLogger.Log("LoginQueueBase.OnMouseLeave() - Left Leave Button");
            if (m_ExitText) m_ExitText.SetColor(colorScheme.PrimaryText());
            return true;
        }
        if (w == m_PrioQBtn)
        {
            CuiLogger.Log("LoginQueueBase.OnMouseLeave() - Left Prio Queue Button");
            if (m_PrioText) m_PrioText.SetColor(colorScheme.PrimaryText());
            return true;
        }
        return false;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (button == MouseState.LEFT && w == m_PrioQBtn)
        {
            CuiLogger.Log("LoginQueueBase.OnClick() - Opening Prio Queue URL: " + CustomURL.PriorityQ);
            GetGame().OpenURL(CustomURL.PriorityQ);
            return false;
        }
        return super.OnClick(w, x, y, button);
    }
}

// Final Crash Fix — Executed by DayZ Engine
modded class LoginTimeStatic extends LoginTimeBase
{
    override void SetTime(int time)
    {
        if (!layoutRoot)
        {
            CuiLogger.Log("LoginTimeStatic.SetTime() - layoutRoot is null, skipping call");
            return;
        }

        if (!m_LoadingMsg)
        {
            m_LoadingMsg = TextWidget.Cast(layoutRoot.FindAnyWidget("LoadingMsg"));
            CuiLogger.Log("LoginTimeStatic.SetTime() - Rebinding m_LoadingMsg");
        }

        if (m_LoadingMsg)
        {
            m_LoadingMsg.SetText("CONNECTING TO SERVER IN " + time.ToString());
        }
        else
        {
            CuiLogger.Log("LoginTimeStatic.SetTime() - m_LoadingMsg is still null");
        }

        CuiLogger.Log("LoginTimeStatic.SetTime() - Countdown: " + time.ToString());
    }
}

// Start at Main Menu  ----------------------------------------------------------
modded class DayZGame
{
    override void ConnectLaunch()
    {
        CuiLogger.Log("DayZGame.ConnectLaunch() - Launching game from CLI or menu");
        if (StartMainMenu) { MainMenuLaunch(); }
        else { ConnectFromCLI(); };
    };
}
