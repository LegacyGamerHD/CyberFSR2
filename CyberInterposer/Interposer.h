#ifndef INTERPOSER
#define INTERPOSER

struct NvParameter : NVSDK_NGX_Parameter
{
	virtual void Set(const char* InName, unsigned long long InValue) override;
	virtual void Set(const char* InName, float InValue) override;
	virtual void Set(const char* InName, double InValue) override;
	virtual void Set(const char* InName, unsigned int InValue) override;
	virtual void Set(const char* InName, int InValue) override;
	virtual void Set(const char* InName, ID3D11Resource* InValue) override;
	virtual void Set(const char* InName, ID3D12Resource* InValue) override;
	virtual void Set(const char* InName, void* InValue) override;
	virtual NVSDK_NGX_Result Get(const char* InName, unsigned long long* OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, float* OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, double* OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, unsigned int* OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, int* OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, ID3D11Resource** OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, ID3D12Resource** OutValue) const override;
	virtual NVSDK_NGX_Result Get(const char* InName, void** OutValue) const override;
	virtual void Reset() override;
};

static class Interposer
{
	// Function pointer declarations
	PFN_NVSDK_NGX_Parameter_SetULL pfn_SetULL = nullptr;
	PFN_NVSDK_NGX_Parameter_SetF pfn_SetF = nullptr;
	PFN_NVSDK_NGX_Parameter_SetD pfn_SetD = nullptr;
	PFN_NVSDK_NGX_Parameter_SetUI pfn_SetUI = nullptr;
	PFN_NVSDK_NGX_Parameter_SetI pfn_SetI = nullptr;
	PFN_NVSDK_NGX_Parameter_SetD3d11Resource pfn_SetD3d11Resource = nullptr;
	PFN_NVSDK_NGX_Parameter_SetD3d12Resource pfn_SetD3d12Resource = nullptr;
	PFN_NVSDK_NGX_Parameter_SetVoidPointer pfn_SetVoidPointer = nullptr;
	PFN_NVSDK_NGX_Parameter_GetULL pfn_GetULL = nullptr;
	PFN_NVSDK_NGX_Parameter_GetF pfn_GetF = nullptr;
	PFN_NVSDK_NGX_Parameter_GetD pfn_GetD = nullptr;
	PFN_NVSDK_NGX_Parameter_GetUI pfn_GetUI = nullptr;
	PFN_NVSDK_NGX_Parameter_GetI pfn_GetI = nullptr;
	PFN_NVSDK_NGX_Parameter_GetD3d11Resource pfn_GetD3d11Resource = nullptr;
	PFN_NVSDK_NGX_Parameter_GetD3d12Resource pfn_GetD3d12Resource = nullptr;
	PFN_NVSDK_NGX_Parameter_GetVoidPointer pfn_GetVoidPointer = nullptr;

	// Function that loads the dependent DLL and retrieves function pointers
	bool LoadDependentDLL();
};



#endif