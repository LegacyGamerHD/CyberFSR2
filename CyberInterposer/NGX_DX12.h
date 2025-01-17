#include "pch.h"


#ifndef CyInt_DX12_INTERPOSER_H
#define CyInt_DX12_INTERPOSER_H

#include "Common.h"

//#include "Config.h"
//#include "DirectXHooks.h"
//#include "Util.h"

#ifdef CyberInterposer_DO_DX12

#include <D3D12.h>
#include <d3dcompiler.h>

#include "CI_Logging.h"

namespace CyberInterposer
{
    struct PFN_Table_NVNGX_DX12 : public  PFN_Table_T {
        PFN_NVSDK_NGX_Parameter_SetD3d12Resource pfn_SetD3d12Resource = nullptr;
        PFN_NVSDK_NGX_Parameter_GetD3d12Resource pfn_GetD3d12Resource = nullptr;

        PFN_NVSDK_NGX_D3D12_Init pfn_D3D12_Init = nullptr;
        PFN_NVSDK_NGX_D3D12_Init_Ext pfn_D3D12_Init_Ext = nullptr;
        PFN_NVSDK_NGX_D3D12_Init_ProjectID pfn_D3D12_Init_ProjectID = nullptr;
        PFN_NVSDK_NGX_D3D12_Init_with_ProjectID pfn_D3D12_Init_with_ProjectID = nullptr;

        PFN_NVSDK_NGX_D3D12_Shutdown pfn_D3D12_Shutdown = nullptr;
        PFN_NVSDK_NGX_D3D12_Shutdown1 pfn_D3D12_Shutdown1 = nullptr;

        PFN_NVSDK_NGX_D3D12_GetCapabilityParameters pfn_D3D12_GetCapabilityParameters = nullptr;
        PFN_NVSDK_NGX_D3D12_GetParameters pfn_D3D12_GetParameters = nullptr;

        PFN_NVSDK_NGX_D3D12_GetScratchBufferSize pfn_D3D12_GetScratchBufferSize = nullptr;

        PFN_NVSDK_NGX_D3D12_AllocateParameters pfn_D3D12_AllocateParameters = nullptr;
        PFN_NVSDK_NGX_D3D12_DestroyParameters pfn_D3D12_DestroyParameters = nullptr;

        PFN_NVSDK_NGX_D3D12_CreateFeature pfn_D3D12_CreateFeature = nullptr;
        PFN_NVSDK_NGX_D3D12_ReleaseFeature pfn_D3D12_ReleaseFeature = nullptr;
        PFN_NVSDK_NGX_D3D12_EvaluateFeature pfn_D3D12_EvaluateFeature = nullptr;
        PFN_NVSDK_NGX_D3D12_EvaluateFeature_C pfn_D3D12_EvaluateFeature_C = nullptr;

        PFN_NVSDK_NGX_D3D12_GetFeatureRequirements pfn_D3D12_GetFeatureRequirements = nullptr;

        bool LoadDLL(HMODULE inputFile, bool populateChildren) override;
    };
}

// Expose_API void C_Declare NVSDK_NGX_Parameter_SetD3d12Resource(NVSDK_NGX_Parameter* InParameter, const char* InName, ID3D12Resource* InValue);
//Expose_API  NVSDK_NGX_Result C_Declare NVSDK_NGX_Parameter_GetD3d12Resource(NVSDK_NGX_Parameter* InParameter, const char* InName, ID3D12Resource** OutValue);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Init(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D12Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Init(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D12Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Init_Ext(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D12Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion, unsigned long long Inflags);

// Expose_API NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Init_Ext(unsigned long long InApplicationId, const wchar_t* InApplicationDataPath, ID3D12Device* InDevice, NVSDK_NGX_Version InSDKVersion, const char* Apointer1, const char* Apointer2);


NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Init_ProjectID(const char* InProjectId, NVSDK_NGX_EngineType InEngineType, const char* InEngineVersion, const wchar_t* InApplicationDataPath, ID3D12Device* InDevice, const NVSDK_NGX_FeatureCommonInfo* InFeatureInfo, NVSDK_NGX_Version InSDKVersion);


NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Shutdown(void);
NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_Shutdown1(ID3D12Device* InDevice);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_GetCapabilityParameters(NVSDK_NGX_Parameter** OutParameters);
NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_GetParameters(NVSDK_NGX_Parameter** OutParameters);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_GetScratchBufferSize(NVSDK_NGX_Feature InFeatureId, const NVSDK_NGX_Parameter* InParameters, size_t* OutSizeInBytes);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_AllocateParameters(NVSDK_NGX_Parameter** OutParameters);
NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_DestroyParameters(NVSDK_NGX_Parameter* InParameters);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_CreateFeature(ID3D12Device* InDevice, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_CreateFeature(ID3D12GraphicsCommandList* InCmdList, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_ReleaseFeature(NVSDK_NGX_Handle* InHandle);


NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_ReleaseFeature(NVSDK_NGX_Handle* InHandle);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_EvaluateFeature(ID3D12GraphicsCommandList* InCmdList, const NVSDK_NGX_Handle* InFeatureHandle, const NVSDK_NGX_Parameter* InParameters, PFN_NVSDK_NGX_ProgressCallback InCallback);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_EvaluateFeature_C(ID3D12GraphicsCommandList* InCmdList, const NVSDK_NGX_Handle* InFeatureHandle, const NVSDK_NGX_Parameter* InParameters, PFN_NVSDK_NGX_ProgressCallback_C InCallback);

NVSDK_NGX_Result C_Declare NVSDK_NGX_D3D12_GetFeatureRequirements(IDXGIAdapter* Adapter, const NVSDK_NGX_FeatureDiscoveryInfo* FeatureDiscoveryInfo, NVSDK_NGX_FeatureRequirement* OutSupported);

// external\FidelityFX-FSR2\src\ffx-fsr2-api\ffx_fsr2_interface.h
// external\nvngx_dlss_sdk\include\nvsdk_ngx_defs.h
// external\nvngx_dlss_sdk\include\nvsdk_ngx_helpers.h


#endif

#endif
