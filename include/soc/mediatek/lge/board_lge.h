#ifndef	__SOC_MTK_BOARD_LGE_H
#define	__SOC_MTK_BOARD_LGE_H

typedef enum {
	HW_REV_0	= 0,
	HW_REV_0_1,
	HW_REV_A,
	HW_REV_B,
	HW_REV_C,
	HW_REV_1_0,
	HW_REV_1_1,
	HW_REV_MAX,
} hw_rev_type;

hw_rev_type lge_get_board_revno(void);

enum lge_laf_mode_type {
    LGE_LAF_MODE_NORMAL = 0,
    LGE_LAF_MODE_LAF,
};

extern unsigned int laf_boot;

enum lge_laf_mode_type lge_get_laf_mode(void);
bool lge_get_laf_mid(void);
int lge_get_bootreason(void);
/* for touch & display dualization */
bool is_lcm_name(char *lcm_full_name);
char* lge_get_lcm_name(void);
bool is_device_lcm_name(char *d_lcm_name);
char* lge_get_device_lcm_name(void);

char *lge_get_model_name(void);

int lge_get_wm_id(void);

#ifdef CONFIG_LGE_PM
const char* unified_bootmode_region(void);
#endif

#endif	/* __SOC_MTK_BOARD_LGE_H */
