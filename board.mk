include $(BOARD_DIR)/firmware/firmware.mk


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=FALSE

DDEFS += -DEFI_UNIT_TEST=0 -DEFI_PROD_CODE=1 -DEFI_SIMULATOR=0

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
# DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15

# EGT chip
#un-comment to enable
#DDEFS += -DEFI_MAX_31855=TRUE

#see main repo for details on this any many other optional subsystems. We have too many, one has to choose what fits into his choice of stm32
#DDEFS += -DEFI_ONBOARD_MEMS=TRUE

# User can configure LIN/K-line interface
#DDEFS += -DEFI_KLINE=TRUE
DDEFS += -DKLINE_SERIAL_DEVICE_RX=Gpio::D6 -DKLINE_SERIAL_DEVICE_TX=Gpio::D5
DDEFS += -DKLINE_SERIAL_DEVICE=SD1
#DDEFS += -DSTM32_SERIAL_USE_USART1=TRUE
