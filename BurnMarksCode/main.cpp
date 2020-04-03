#include <android/log.h>
#include "../beatsaber-hook/shared/utils/utils.h"
#include "../beatsaber-hook/shared/utils/utils-functions.h"
#include "../beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "../beatsaber-hook/shared/utils/utils-functions.h"
bool burnMarkTrailsEnabled = true;
MAKE_HOOK_OFFSETLESS(MainSettingsModelSO, void, Il2CppObject* self, bool  forced) {
	Il2CppObject *burnMark;
	il2cpp_utils::GetFieldValue(&burnMark, self, "burnMarkTrailsEnabled");
	il2cpp_utils::RunMethod(burnMark, "set_value", burnMarkTrailsEnabled);
	MainSettingsModelSO(self, forced);
}
extern "C" void load() {
	log(INFO, "Installing BurnMarksMod!");
	INSTALL_HOOK_OFFSETLESS(MainSettingsModelSO, il2cpp_utils::FindMethodUnsafe("", "MainSettingsModelSO", "Load", 1));
	log(INFO, "Installed!");
}
