#include "pch.h"

void boardTuneDefaults() {
	engineConfiguration->displacement = 0.15; // 100cc
	engineConfiguration->cylindersCount = 1;
	engineConfiguration->firingOrder = FO_1;

	/**
	 * 12/1 trigger
	 */
	engineConfiguration->trigger.type = trigger_type_e::TT_TOOTHED_WHEEL;
	engineConfiguration->trigger.customTotalToothCount = 12;
	engineConfiguration->trigger.customSkippedToothCount = 1;
}
