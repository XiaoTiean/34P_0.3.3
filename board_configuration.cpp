#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
    // engineConfiguration->injectionPins[0] = Gpio::F13;
    // engineConfiguration->ignitionPins[0] = Gpio::E15;

//   engineConfiguration->triggerInputPins[0] = Gpio::B1;
//	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;

//	engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;

//	engineConfiguration->clt.adcChannel = EFI_ADC_1;

//	engineConfiguration->iat.adcChannel = EFI_ADC_2;


    	// 5.6k high side/10k low side = 1.56 ratio divider
  //  	engineConfiguration->analogInputDividerCoefficient = 1.56f;

    	// 6.34k high side/ 1k low side
//    	engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;

//	engineConfiguration->adcVcc = 3.3f;

//	engineConfiguration->clt.config.bias_resistor = 2490;
//	engineConfiguration->iat.config.bias_resistor = 2490;


	// Battery sense on PA0
//	engineConfiguration->vbattAdcChannel = EFI_ADC_0;

    engineConfiguration->enableKline = false;
    engineConfiguration->kLineBaudRate = 10400;
	engineConfiguration->hondaK = false;
	engineConfiguration->verboseKLine = false;

#if EFI_PROD_CODE
    efiSetPadMode("K-Line UART RX", Gpio::KLINE_SERIAL_DEVICE_RX, PAL_MODE_ALTERNATE(TS_SERIAL_AF));
    efiSetPadMode("K-Line UART TX", Gpio::KLINE_SERIAL_DEVICE_TX, PAL_MODE_ALTERNATE(TS_SERIAL_AF));
#endif /* EFI_PROD_CODE */
 
    static SerialConfig cfg = {
        #if EFI_PROD_CODE
            .speed = 0,
            .cr1 = 0,
            .cr2 = USART_CR2_STOP1_BITS | USART_CR2_LINEN,
            .cr3 = 0,
        #endif // EFI_PROD_CODE
    };
 
    if (engineConfiguration->kLineBaudRate < 100)
        engineConfiguration->kLineBaudRate = KLINE_BAUD_RATE;
    cfg.speed = engineConfiguration->kLineBaudRate;
 
    sdStart(klDriver, &cfg);
#endif // EFI_KLINE
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
