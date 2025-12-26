EventScript_PORTAPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PORTAPCMainMenu
	end

EventScript_PORTAPCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_PORTAAccessPC
	end

EventScript_PORTAAccessPC::
	switch VAR_RESULT
	case 0, EventScript_PORTAAccessPokemonStorage
	case 1, EventScript_PORTAAccessPlayersPC
	case 2, EventScript_PORTAAccessHallOfFame
	case 3, EventScript_PORTATurnOffPC
	case MULTI_B_PRESSED, EventScript_PORTATurnOffPC
	end

EventScript_PORTAAccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PORTAPCMainMenu
	end

EventScript_PORTAAccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_PORTAAccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_PORTAAccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PORTAPCMainMenu
	end

EventScript_PORTAAccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_PORTAAccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_PORTATurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	releaseall
	end

EventScript_PORTAAccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_PORTATurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_PORTAAccessPC
	end
