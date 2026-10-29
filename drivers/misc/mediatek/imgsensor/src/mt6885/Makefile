# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2020 MediaTek Inc.

MTK_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
ARCH_MTK_PROJECT := $(subst ",,$(CONFIG_ARCH_MTK_PROJECT))
IMGSENSOR_DRIVER_PATH  := $(srctree)/drivers/misc/mediatek/imgsensor/src
MTK_DRIVER_PATH  := $(srctree)/drivers/misc/mediatek
COMMON_VERSION := v1_1

ifeq ($(CONFIG_MTK_PLATFORM), "mt6885")
subdir-ccflags-y += -DIMGSENSOR_MT6885
endif

ifeq (,$(wildcard $(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/$(1)))
subdir-ccflags-y += -I$(IMGSENSOR_DRIVER_PATH)/common/$(COMMON_VERSION) \
	-I$(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/seninf/ \
	-I$(MTK_DRIVER_PATH)/mmdvfs \
	-I$(srctree)/drivers/i2c/busses/
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_hw.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_i2c.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_legacy.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_proc.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_sensor_list.o
obj-y                           += ../common/$(COMMON_VERSION)/seninf_clk.o
obj-y				+= ../common/$(COMMON_VERSION)/seninf.o
obj-y				+= ../common/$(COMMON_VERSION)/imgsensor_pwr_seq.o
else
subdir-ccflags-y +=  -I$(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/$(1) \
	-I$(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/seninf/ \
	-I$(MTK_DRIVER_PATH)/mmdvfs \
	-I$(srctree)/drivers/i2c/busses/
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor_hw.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor_i2c.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor_legacy.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor_proc.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/imgsensor_sensor_list.o
obj-y				+= ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/seninf.o
obj-y                           += ../$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/seninf_clk.o
endif
define FILTER_DRV
ifeq ($(wildcard $(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/imgsensor/$(1)),)
ifeq ($(wildcard $(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/$(1)),)
common_drv += ../common/$(COMMON_VERSION)/$(1)/
else
platform_drv += $(1)/
endif
else
project_drv += ./camera_project/$(ARCH_MTK_PROJECT)/imgsensor/$(1)/
endif
endef
$(foreach drv,$(subst $\",,$(CONFIG_CUSTOM_KERNEL_IMGSENSOR)),$(eval $(call FILTER_DRV,$(drv))))
ifneq ($(common_drv),)
$(info imgsensor drv by common $(common_drv))
endif
obj-y				+= $(common_drv)
ifneq ($(platform_drv),)
$(info imgsensor drv by platform $(platform_drv))
endif
obj-y				+= $(platform_drv)

ifneq ($(project_drv),)
$(info imgsensor drv by project $(project_drv))
endif
obj-y				+= $(project_drv)

ifeq (,$(wildcard $(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/camera_hw))
subdir-ccflags-y		+= -I$(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_hw
obj-y				+= camera_hw/
ifneq ($(project_drv),)
obj-y				+= camera_project/$(ARCH_MTK_PROJECT)/
endif
else
obj-y				+= camera_project/$(ARCH_MTK_PROJECT)/camera_hw/
subdir-ccflags-y		+= -I$(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/camera_hw
endif

ifeq (,$(wildcard $(IMGSENSOR_DRIVER_PATH)/$(MTK_PLATFORM)/camera_project/$(ARCH_MTK_PROJECT)/camera_hw))
subdir-ccflags-y		+= -I$(IMGSENSOR_DRIVER_PATH)/common/$(COMMON_VERSION)/camera_hw
endif

# Enable parallelism
subdir-ccflags-y += -DSENSOR_PARALLEISM

obj-y += seninf/
