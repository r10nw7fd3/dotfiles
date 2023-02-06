// patches: pertag (https://dwm.suckless.org/patches/pertag/)

static const unsigned int borderpx  = 1; 
static const unsigned int snap      = 16;
static const int showbar            = 1;
static const int topbar             = 1;
static const char* fonts[]          = {"monospace:size=10"};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_main[]        = "#dddddd"; //"#e0a385";
static const char* colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = {col_gray3, col_gray1, col_gray2},
	[SchemeSel]  = {col_gray1, col_main,  col_gray3},
};

static const char* tags[] = {"1", "2", "3", "4"};
static const Rule rules[] = {
	{NULL, NULL, NULL, 0, 0, 0},
};

static const float mfact = 0.5;
static const int nmaster = 1;
static const int resizehints = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{"[]=",      tile},
	{"><>",      NULL},
	{"[M]",      monocle},
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) \
	{MODKEY, KEY, view, {.ui = 1 << TAG}}, \
	{MODKEY|ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, \
	{MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG}}, \
	{MODKEY|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

static char dmenumon[2] = "0";
static const char* dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_main, "-sf", col_gray1, NULL};
static const char* termcmd[] = {"alacritty", NULL};
static const char* pavolupcmd[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL};
static const char* pavoldowncmd[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL};

static Key keys[] = {
	{MODKEY, XK_Return, spawn, {.v = termcmd}},
	{MODKEY|ShiftMask, XK_Return, spawn, {.v = dmenucmd}},
	{MODKEY, XK_c, killclient, {0}},
	{MODKEY, XK_s, zoom, {0}},
	{MODKEY, XK_b, togglebar, {0}},
	{MODKEY, XK_Tab, view, {0}},
	{MODKEY, XK_a, focusstack, {.i = +1}},
	{MODKEY, XK_k, incnmaster, {.i = +1}},
	{MODKEY, XK_l, incnmaster, {.i = -1}},
	{MODKEY, XK_o, setmfact, {.f = -0.05}},
	{MODKEY, XK_p, setmfact, {.f = +0.05}},
	{MODKEY, XK_space, setlayout, {0}},
	{MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
	{MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
	{MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
	{MODKEY|ShiftMask, XK_space, togglefloating, {0}},
	{MODKEY, XK_comma, focusmon, {.i = -1}},
	{MODKEY, XK_period, focusmon, {.i = -1}},
	{MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1}},
	{MODKEY|ShiftMask, XK_period, tagmon, {.i = +1}},
	{MODKEY|ShiftMask, XK_q, quit, {0}},
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)

	{MODKEY|ControlMask, XK_s, spawn, {.v = pavolupcmd}},
	{MODKEY|ControlMask, XK_a, spawn, {.v = pavoldowncmd}},
};

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ClkLtSymbol,          0,              Button1,        setlayout,      {0}},
	{ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]}},
	{ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd }},
	{ClkClientWin,         MODKEY,         Button1,        movemouse,      {0}},
	{ClkClientWin,         MODKEY,         Button2,        togglefloating, {0}},
	{ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0}},
	{ClkTagBar,            0,              Button1,        view,           {0}},
	{ClkTagBar,            0,              Button3,        toggleview,     {0}},
	{ClkTagBar,            MODKEY,         Button1,        tag,            {0}},
	{ClkTagBar,            MODKEY,         Button3,        toggletag,      {0}},
};
