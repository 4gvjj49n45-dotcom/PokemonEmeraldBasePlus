EventScript_USEREPEL::
	goto_if_eq VAR_ENDLESS_REPEL, 0, EventScript_USEENDLESS
	goto_if_eq VAR_ENDLESS_REPEL, 1, EventScript_ENDENDLESS
	releaseall


EventScript_USEENDLESS::
	lockall
	msgbox gText_EndlessRepel, MSGBOX_DEFAULT
	setvar VAR_ENDLESS_REPEL 1
	releaseall
	end

EventScript_ENDENDLESS::
	lockall
	msgbox gText_StopEndlessRepel, MSGBOX_DEFAULT
	setvar VAR_ENDLESS_REPEL 0
	releaseall
	end
