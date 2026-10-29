ccflags-y += -I$(srctree)/drivers/misc/mediatek/include -I$(srctree)/drivers/soc/mediatek/lge/power
subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/typec/tcpc/inc

obj-$(CONFIG_MACH_LGE)				+= devices_lge.o
obj-$(CONFIG_LGE_BOOT_MODE) += lge_boot_mode.o
obj-$(CONFIG_LGE_HANDLE_PANIC)		+= lge_handle_panic.o
obj-$(CONFIG_LGE_EARJACK_DEBUGGER)	+= lge_earjack_debugger.o
obj-$(CONFIG_LGE_USB_SBU_SWITCH) += lge_sbu_switch.o
obj-$(CONFIG_LGE_PM_PRM) += power/main/lge_prm.o
obj-$(CONFIG_LGE_PM_PRM) += power/sben/lge_sben.o
obj-$(CONFIG_LGE_PM_PRM) += power/dd/lge_dd.o
