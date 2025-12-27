#include "global.h"
#include "event_data.h"   // VarGet/VarSet
#include "constants/vars.h"   // VAR_LEVEL_CAP (if needed)
#include "constants/flags.h"  // FLAG_DEFEATED_...

void Special_AdjustLevelCaps(void)
{
    // Check highest progression first (early catches remain TRUE forever)
    if (FlagGet(FLAG_DEFEATED_SOOTOPOLIS_GYM))
        VarSet(VAR_LEVEL_CAP, 55);
    else if (FlagGet(FLAG_DEFEATED_MOSSDEEP_GYM))
        VarSet(VAR_LEVEL_CAP, 46);
    else if (FlagGet(FLAG_DEFEATED_FORTREE_GYM))
        VarSet(VAR_LEVEL_CAP, 42);
    else if (FlagGet(FLAG_DEFEATED_PETALBURG_GYM))
        VarSet(VAR_LEVEL_CAP, 33);
    else if (FlagGet(FLAG_DEFEATED_LAVARIDGE_GYM))
        VarSet(VAR_LEVEL_CAP, 31);
    else if (FlagGet(FLAG_DEFEATED_MAUVILLE_GYM))
        VarSet(VAR_LEVEL_CAP, 29);
    else if (FlagGet(FLAG_DEFEATED_DEWFORD_GYM))
        VarSet(VAR_LEVEL_CAP, 24);
    else if (FlagGet(FLAG_DEFEATED_RUSTBORO_GYM))
        VarSet(VAR_LEVEL_CAP, 19);
    else
        VarSet(VAR_LEVEL_CAP, 15); // default 
}
