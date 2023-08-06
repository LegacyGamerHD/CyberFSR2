#include "pch.h"
#include "NGX_Interposer.h"

using namespace CyberInterposer;

bool CyberInterposer::PFN_Table_NVNGX_Vulkan::LoadDLL(HMODULE hModule, bool populateChildren)
{
	CyberLogArgs(hModule, populateChildren);

	if (hModule == nullptr) {
		return false;
	}
	pfn_VULKAN_Init = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_Init>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_Init"));
	pfn_VULKAN_Init_Ext = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_Init_Ext>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_Init_Ext"));
	pfn_VULKAN_Init_ProjectID = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_Init_ProjectID>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_Init_ProjectID"));

	pfn_VULKAN_Shutdown = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_Shutdown>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_Shutdown"));
	pfn_VULKAN_Shutdown1 = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_Shutdown1>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_Shutdown1"));

	pfn_VULKAN_GetCapabilityParameters = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_GetCapabilityParameters>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_GetCapabilityParameters"));
	pfn_VULKAN_GetParameters = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_GetParameters>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_GetParameters"));

	pfn_VULKAN_AllocateParameters = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_AllocateParameters>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_AllocateParameters"));
	pfn_VULKAN_DestroyParameters = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_DestroyParameters>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_DestroyParameters"));

	pfn_VULKAN_GetScratchBufferSize = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_GetScratchBufferSize>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_GetScratchBufferSize"));

	pfn_VULKAN_CreateFeature = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_CreateFeature>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_CreateFeature"));
	pfn_VULKAN_ReleaseFeature = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_ReleaseFeature>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_ReleaseFeature"));
	pfn_VULKAN_EvaluateFeature = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_EvaluateFeature>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_EvaluateFeature"));
	pfn_VULKAN_EvaluateFeature_C = reinterpret_cast<PFN_NVSDK_NGX_VULKAN_EvaluateFeature_C>(GetProcAddress(hModule, "NVSDK_NGX_VULKAN_EvaluateFeature_C"));

    bool foundFunctions = true;

#define CyDLLLoadLog(name) \
	do { \
		const bool found = (name == nullptr); \
		if(found){ \
			CyberLOGi(#name, " found"); \
		} \
		else { \
			CyberLOGi(#name, " not found"); \
		} \
		foundFunctions = false; \
	} while(false)

	CyDLLLoadLog(pfn_VULKAN_Init);
	CyDLLLoadLog(pfn_VULKAN_Init_Ext);
	CyDLLLoadLog(pfn_VULKAN_Init_ProjectID);
	CyDLLLoadLog(pfn_VULKAN_Shutdown);
	CyDLLLoadLog(pfn_VULKAN_Shutdown1);
	CyDLLLoadLog(pfn_VULKAN_GetCapabilityParameters);
	CyDLLLoadLog(pfn_VULKAN_GetParameters);
	CyDLLLoadLog(pfn_VULKAN_GetScratchBufferSize);
	CyDLLLoadLog(pfn_VULKAN_CreateFeature);
	CyDLLLoadLog(pfn_VULKAN_ReleaseFeature);
	CyDLLLoadLog(pfn_VULKAN_EvaluateFeature);
	CyDLLLoadLog(pfn_VULKAN_EvaluateFeature_C);
	CyDLLLoadLog(pfn_VULKAN_AllocateParameters);
	CyDLLLoadLog(pfn_VULKAN_DestroyParameters);

#undef CyDLLLoadLog

    return foundFunctions;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_Init(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, VkInstance InInstance, VkPhysicalDevice InPD, VkDevice InDevice, PFN_vkGetInstanceProcAddr InGIPA, PFN_vkGetDeviceProcAddr InGDPA, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
{
	CyberLogArgs(InApplicationId, InApplicationDataPath, InInstance, InPD, InDevice, InGIPA, InGDPA, InFeatureInfo, InSDKVersion);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_Init_ProjectID(const char* InProjectId, NVSDK_NGX_EngineType InEngineType, const char* InEngineVersion, const wchar_t* InApplicationDataPath, VkInstance InInstance, VkPhysicalDevice InPD, VkDevice InDevice, PFN_vkGetInstanceProcAddr InGIPA, PFN_vkGetDeviceProcAddr InGDPA, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
{
	CyberLogArgs(InProjectId, InEngineType, InEngineVersion, InApplicationDataPath, InInstance, InPD, InDevice, InGIPA, InGDPA, InFeatureInfo, InSDKVersion);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_VULKAN_Init(0x1337, InApplicationDataPath, InInstance, InPD, InDevice, InGIPA, InGDPA, InFeatureInfo, InSDKVersion);
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_Init_with_ProjectID(const char* InProjectId, NVSDK_NGX_EngineType InEngineType, const char* InEngineVersion, const wchar_t* InApplicationDataPath, VkInstance InInstance, VkPhysicalDevice InPD, VkDevice InDevice, PFN_vkGetInstanceProcAddr InGIPA, PFN_vkGetDeviceProcAddr InGDPA, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion)
{
	CyberLogArgs(InProjectId, InEngineType, InEngineVersion, InApplicationDataPath, InInstance, InPD, InDevice, InGIPA, InGDPA, InFeatureInfo, InSDKVersion);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_VULKAN_Init(0x1337, InApplicationDataPath, InInstance, InPD, InDevice, InGIPA, InGDPA, InFeatureInfo, InSDKVersion);
}

NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_VULKAN_Shutdown(void)
{
	CyberLOG();

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_VULKAN_Shutdown1(VkDevice InDevice)
{
	CyberLogArgs(InDevice);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_GetParameters(NVSDK_NGX_Parameter** OutParameters)
{
	CyberLogArgs(OutParameters);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_AllocateParameters(NVSDK_NGX_Parameter** OutParameters)
{
	CyberLogArgs(OutParameters);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_GetCapabilityParameters(NVSDK_NGX_Parameter** OutParameters)
{
	CyberLogArgs(OutParameters);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_DestroyParameters(NVSDK_NGX_Parameter* InParameters)
{
	CyberLogArgs(InParameters);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_GetScratchBufferSize(NVSDK_NGX_Feature InFeatureId, const NVSDK_NGX_Parameter* InParameters, size_t* OutSizeInBytes)
{
	CyberLogArgs(InFeatureId, InParameters, OutSizeInBytes);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_CreateFeature(VkCommandBuffer InCmdBuffer, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle)
{
	CyberLogArgs(InCmdBuffer, InFeatureID, InParameters, OutHandle);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_CreateFeature1(VkDevice InDevice, VkCommandBuffer InCmdList, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle)
{
	CyberLogArgs(InDevice, InCmdList, InFeatureID, InParameters, OutHandle);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_ReleaseFeature(NVSDK_NGX_Handle* InHandle)
{
	CyberLogArgs(InHandle);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}

NVSDK_NGX_Result NVSDK_NGX_VULKAN_EvaluateFeature(VkCommandBuffer InCmdList, const NVSDK_NGX_Handle* InFeatureHandle, const NVSDK_NGX_Parameter* InParameters, PFN_NVSDK_NGX_ProgressCallback InCallback)
{
	CyberLogArgs(InCmdList, InFeatureHandle, InParameters, InCallback);

	// is pointer good? cast pointer and call it and return any results!
	return NVSDK_NGX_Result_Success;
}