
// USB based keyboard scan codes
#define KEY_MOD_LCTRL 	0x01
#define KEY_MOD_LSHIFT 	0x02
#define KEY_MOD_LALT	0x04
#define KEY_MOD_LMETA	0x08
#define KEY_MOD_RCTRL	0x10
#define KEY_MOD_RSHIFT	0x20
#define KEY_MOD_RALT	0x40
#define KEY_MOD_RMETA	0x80

#define KEY_NONE		0x00
#define KEY_ERR_OVF		0x01
#define KEY_ERR_POST	0x02
#define KEY_ERR_UNDEF	0x03
#define KEY_A			0x04
#define KEY_B			0x05
#define KEY_C			0x06
#define KEY_D			0x07
#define KEY_E			0x08
#define KEY_F			0x09
#define KEY_G			0x0A
#define KEY_H			0x0B
#define KEY_I			0x0C
#define KEY_J			0x0D
#define KEY_K			0x0E
#define KEY_L			0x0F
#define KEY_M			0x10
#define KEY_N			0x11
#define KEY_O			0x12
#define KEY_P			0x13
#define KEY_Q			0x14
#define KEY_R			0x15
#define KEY_S			0x16
#define KEY_T			0x17
#define KEY_U			0x18
#define KEY_V			0x19
#define KEY_W			0x1A
#define KEY_X			0x1B
#define KEY_Y			0x1C
#define KEY_Z			0x1D
#define KEY_1			0x1E
#define KEY_2			0x1F
#define KEY_3			0x20
#define KEY_4			0x21
#define KEY_5			0x22
#define KEY_6			0x23
#define KEY_7			0x24
#define KEY_8			0x25
#define KEY_9			0x26
#define KEY_0			0x27
#define KEY_ENTER		0x28
#define KEY_ESCAPE		0x29
#define KEY_BACKSP		0x2A
#define KEY_TAB			0x2B
#define KEY_SPACE		0x2C
#define KEY_MINUS		0x2D
#define KEY_EQUAL		0x2E
#define KEY_LEFTBRACE	0x2F
#define KEY_RIGHTBRACE	0x30
#define KEY_BACKSLASH	0x
#define KEY_HASHTILDE	0x
#define KEY_SEMICOLON	0x
#define KEY_APOSTRPHE	0x
#define KEY_GRAVE		0x
#define KEY_COMMA		0x
#define KEY_DOT			0x
#define KEY_SLASH		0x
#define KEY_CAPSLOCK	0x
#define KEY_F1			0x
#define KEY_F2			0x
#define KEY_F3			0x
#define KEY_F4			0x
#define KEY_F5			0x
#define KEY_F6			0x
#define KEY_F7			0x
#define KEY_F8			0x
#define KEY_F9			0x
#define KEY_F10			0x
#define KEY_F11			0x
#define KEY_F12			0x
#define KEY_SYSREQ		0x
#define KEY_SCROLLLOCK	0x
#define KEY_PAUSE		0x
#define KEY_INSERT		0x
#define KEY_HOME		0x
#define KEY_PAGEUP		0x
#define KEY_DELETE		0x
#define KEY_END			0x
#define KEY_PAGEDOWN	0x
#define KEY_RIGHT		0x
#define KEY_LEFT		0x
#define KEY_DOWN		0x
#define KEY_UP			0x
#define KEY_NUMLOCK		0x
#define KEY_KP_SLASH	0x
#define KEY_KP_ASTERISK	0x
#define KEY_KP_MINUS	0x
#define KEY_KP_PLUS		0x
#define KEY_KP_ENTER	0x
#define KEY_KP_1		0x
#define KEY_KP_2		0x
#define KEY_KP_3		0x
#define KEY_KP_4		0x
#define KEY_KP_5		0x
#define KEY_KP_6		0x
#define KEY_KP_7		0x
#define KEY_KP_8		0x
#define KEY_KP_9		0x
#define KEY_KP_0		0x
#define KEY_KP_DOT		0x
#define KEY_102ND		0x
#define KEY_APPLICATION	0x
#define KEY_POWER		0x
#define KEY_KP_EQUAL	0x
#define KEY_F13			0x
#define KEY_F14			0x
#define KEY_F15			0x
#define KEY_F16			0x
#define KEY_F17			0x
#define KEY_F18			0x
#define KEY_F19			0x
#define KEY_F20			0x
#define KEY_F21			0x
#define KEY_F22			0x
#define KEY_F23			0x
#define KEY_F24			0x
#define KEY_OPEN		0x
#define KEY_HELP		0x
#define KEY_RCLICKMENU	0x
#define KEY_STOP		0x
#define KEY_AGAIN		0x
#define KEY_UNDO		0x
#define KEY_CUT			0x
#define KEY_COPY		0x
#define KEY_PASTE		0x
#define KEY_FIND		0x
#define KEY_MUTE		0x
#define KEY_VOLUMEUP	0x
#define KEY_VOLUMEDOWN	0x
#define KEY_CAPS_LOCK	0x
#define KEY_NUM_LOCK	0x
#define KEY_SCROLL_LOCK	0x
#define KEY_KP_COMMA	0x
#define KEY_KP_EQUAL	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x
#define KEY_	0x

static const uint8_t keypress_0x00[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x01[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x02[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x03[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x04[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x05[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x06[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x07[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x08[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x09[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x0A[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x0B[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x0C[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x0D[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x0E[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x0F[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};
static const uint8_t keypress_0x10[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t keypress_0x11[16] = {
	KEY_ERR_OVF,	// 0x00
	KEY_ERR_OVF,	// 0x01
	KEY_ERR_OVF,	// 0x02
	KEY_ERR_OVF,	// 0x03	
	
	KEY_ERR_OVF,	// 0x04
	KEY_ERR_OVF,	// 0x05
	KEY_ERR_OVF,	// 0x06
	KEY_ERR_OVF,	// 0x07
	
	KEY_ERR_OVF,	// 0x08
	KEY_ERR_OVF,	// 0x09
	KEY_ERR_OVF,	// 0x0A
	KEY_ERR_OVF,	// 0x0B
	
	KEY_ERR_OVF,	// 0x0C
	KEY_ERR_OVF,	// 0x0D
	KEY_ERR_OVF,	// 0x0E
	KEY_ERR_OVF		// 0x0F
};

static const uint8_t crc_read_pak[256] = {
	0x00
};

#endif