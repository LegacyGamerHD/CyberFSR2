#include "pch.h"
#include "Config.h"
#include "Util.h"
#include "NvParameter.h"
#include "CyberFsr.h"

constexpr float NO_VALUEf = -128.125;
constexpr int NO_VALUEi = -128;

namespace CyberFSR
{
	void NvParameter::Set(const char* InName, unsigned long long InValue)
	{
		constexpr NvParameterType nvType = NvULL;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			break;
		}
	}

	void NvParameter::Set(const char* InName, float InValue)
	{
		constexpr NvParameterType nvType = NvFloat;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::MV_Scale_X:
			//MVScaleX = InValue / 2;
			MVScaleX = InValue;
			//MVScaleX = OutWidth;
			break;
		case Util::NvParameter::MV_Scale_Y:
			//MVScaleY = InValue / 2;
			MVScaleY = InValue;
			//MVScaleY = OutHeight;
			break;
		case Util::NvParameter::Jitter_Offset_X:
			JitterOffsetX = InValue;
			break;
		case Util::NvParameter::Jitter_Offset_Y:
			JitterOffsetY = InValue;
			break;
		case Util::NvParameter::Sharpness: {
			static float lastSharp;
			Sharpness = InValue;
			if (Sharpness != lastSharp) 
			{
				ResetRender = true;
				lastSharp = Sharpness;
			}
		}
			break;
		default:
			BadThingHappened();
			break;
		}
	}

	void NvParameter::Set(const char* InName, double InValue)
	{
		constexpr NvParameterType nvType = NvDouble;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			break;
		}
	}

	void NvParameter::Set(const char* InName, unsigned int InValue)
	{
		constexpr NvParameterType nvType = NvUInt;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::Width:
			Width = InValue;
			break;
		case Util::NvParameter::Height:
			Height = InValue;
			break;
		case Util::NvParameter::DLSS_Render_Subrect_Dimensions_Width:
			Render_Subrect_Dimensions_Width = InValue;
			break;
		case Util::NvParameter::DLSS_Render_Subrect_Dimensions_Height:
			Render_Subrect_Dimensions_Height = InValue;
			break;
		case Util::NvParameter::OutWidth:
			OutWidth = InValue;
			break;
		case Util::NvParameter::OutHeight:
			OutHeight = InValue;
			break;
		case Util::NvParameter::CreationNodeMask:
			CreationNodeMask = InValue;
			break;
		case Util::NvParameter::VisibilityNodeMask:
			VisibilityNodeMask = InValue;
			break;
		default:
			BadThingHappened();
			break;
		}
	}

	void NvParameter::Set(const char* InName, int InValue)
	{
		constexpr NvParameterType nvType = NvInt;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::PerfQualityValue:
			PerfQualityValue = static_cast<NVSDK_NGX_PerfQuality_Value>(InValue);
			break;
		case Util::NvParameter::RTXValue:
			RTXValue = InValue;
			break;
		case Util::NvParameter::FreeMemOnReleaseFeature:
			FreeMemOnReleaseFeature = InValue;
			break;
		case Util::NvParameter::Reset:
			ResetRender = InValue;
			break;
		case Util::NvParameter::DLSS_Feature_Create_Flags:
			Hdr = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_IsHDR;
			LowRes = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_MVLowRes;
			JitterMotion = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_MVJittered;
			DepthInverted = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_DepthInverted;
			//Reserved = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_Reserved_0;
			EnableSharpening = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_DoSharpening;
			AutoExposure = InValue & NVSDK_NGX_DLSS_Feature_Flags::NVSDK_NGX_DLSS_Feature_Flags_AutoExposure;
			break;
		default:
			BadThingHappened();
			break;
		}
	}

	void NvParameter::Set(const char* InName, ID3D11Resource* InValue)
	{
#define SetNVarWithName(setVar, name) if ((setVar = InValue ) && nvType == NvParameterType::NvD3D12Resource ) ((ID3D12Resource*)setVar)->SetName(name)
		constexpr NvParameterType nvType = NvD3D11Resource;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::DLSS_Input_Bias_Current_Color_Mask:
			SetNVarWithName(InputBiasCurrentColorMask, L"Color");
			break;
		case Util::NvParameter::Color:
			SetNVarWithName(Color, L"Color");
			break;
		case Util::NvParameter::Depth:
			SetNVarWithName(Depth, L"Depth");
			break;
		case Util::NvParameter::MotionVectors:
			SetNVarWithName(MotionVectors, L"MotionVectors");
			break;
		case Util::NvParameter::Output:
			SetNVarWithName(Output, L"Output");
			break;
		case Util::NvParameter::TransparencyMask:
			SetNVarWithName(TransparencyMask, L"TransparencyMask");
			break;
		case Util::NvParameter::ExposureTexture:
			SetNVarWithName(ExposureTexture, L"ExposureTexture");
			break;
		default:
			BadThingHappened();
			break;
		}
#undef SetNVarWithName
	}

	void NvParameter::Set(const char* InName, ID3D12Resource* InValue)
	{
#define SetNVarWithName(setVar, name) if ((setVar = InValue ) && nvType == NvParameterType::NvD3D12Resource ) ((ID3D12Resource*)setVar)->SetName(name)
		constexpr NvParameterType nvType = NvD3D12Resource;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::DLSS_Input_Bias_Current_Color_Mask:
			SetNVarWithName(InputBiasCurrentColorMask, L"Color");
			break;
		case Util::NvParameter::Color:
			SetNVarWithName(Color, L"Color");
			break;
		case Util::NvParameter::Depth:
			SetNVarWithName(Depth, L"Depth");
			break;
		case Util::NvParameter::MotionVectors:
			SetNVarWithName(MotionVectors, L"MotionVectors");
			break;
		case Util::NvParameter::Output:
			SetNVarWithName(Output, L"Output");
			break;
		case Util::NvParameter::TransparencyMask:
			SetNVarWithName(TransparencyMask, L"TransparencyMask");
			break;
		case Util::NvParameter::ExposureTexture:
			SetNVarWithName(ExposureTexture, L"ExposureTexture");
			break;
		default:
			BadThingHappened();
			break;
		}
#undef SetNVarWithName
	}

	void NvParameter::Set(const char* InName, void* InValue)
	{
		constexpr NvParameterType nvType = NvVoidPtr;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			break;
		}
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, unsigned long long* OutValue) const
	{
		constexpr NvParameterType nvType = NvULL;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::SizeInBytes:
			*OutValue = SizeInBytes;
			break;
		case Util::NvParameter::OptLevel:
		case Util::NvParameter::OptLevel_E:
			*OutValue = OptLevel;
			break;
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, float* OutValue) const
	{
		constexpr NvParameterType nvType = NvFloat;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);


		switch (inParameter)
		{
		case Util::NvParameter::Sharpness:
			*OutValue = Sharpness;
			break;
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, double* OutValue) const
	{
		constexpr NvParameterType nvType = NvDouble;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, unsigned int* OutValue) const
	{
		constexpr NvParameterType nvType = NvUInt;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::OutWidth:
			*OutValue = OutWidth;
			break;
		case Util::NvParameter::OutHeight:
			*OutValue = OutHeight;
			break;
		case Util::NvParameter::DLSS_Get_Dynamic_Max_Render_Width:
			*OutValue = Max_Render_Width;
			break;
		case Util::NvParameter::DLSS_Get_Dynamic_Max_Render_Height:
			*OutValue = Max_Render_Height;
			break;
		case Util::NvParameter::DLSS_Get_Dynamic_Min_Render_Width:
			//*OutValue = Width / 10;
			*OutValue = Min_Render_Width;
			break;
		case Util::NvParameter::DLSS_Get_Dynamic_Min_Render_Height:
			//*OutValue = Height / 10;
			*OutValue = Min_Render_Height;
			break;
		case Util::NvParameter::DLSS_Render_Subrect_Dimensions_Width:
			*OutValue = Render_Subrect_Dimensions_Width;
			break;
		case Util::NvParameter::DLSS_Render_Subrect_Dimensions_Height:
			*OutValue = Render_Subrect_Dimensions_Height;
			break;
		case Util::NvParameter::SuperSampling_Available:
		case Util::NvParameter::SuperSampling_Available_E:
			*OutValue = SuperSampling_Available; // change this to member!
			break;
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, int* OutValue) const
	{
		constexpr NvParameterType nvType = NvInt;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		case Util::NvParameter::SuperSampling_FeatureInitResult:
			*OutValue = NVSDK_NGX_Result_Success;
			break;
		case Util::NvParameter::SuperSampling_NeedsUpdatedDriver:
			*OutValue = false;
			break;
		case Util::NvParameter::SuperSampling_MinDriverVersionMinor:
			*OutValue = 0;
			break;
		case Util::NvParameter::SuperSampling_MinDriverVersionMajor:
			*OutValue = 0;
			break;
		case Util::NvParameter::IsDevSnippetBranch:
		case Util::NvParameter::IsDevSnippetBranch_E:
			*OutValue = IsDevSnippetBranch; //Dummy value
			break;
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, ID3D11Resource** OutValue) const
	{
		constexpr NvParameterType nvType = NvD3D11Resource;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NvParameter::Get(const char* InName, ID3D12Resource** OutValue) const
	{
		constexpr NvParameterType nvType = NvD3D12Resource;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter)
		{
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_DLSS_GetOptimalSettingsCallback(NVSDK_NGX_Parameter* InParams);
	NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_DLSS_GetStatsCallback(NVSDK_NGX_Parameter* InParams);

	NVSDK_NGX_Result NvParameter::Get(const char* InName, void** OutValue) const
	{
		constexpr NvParameterType nvType = NvVoidPtr;
		auto result = NVSDK_NGX_Result_Success;

		const Util::NvParameter inParameter = Util::NvParameterToEnum(InName);

		switch (inParameter) {
		case Util::NvParameter::DLSSOptimalSettingsCallback:
			*OutValue = NVSDK_NGX_DLSS_GetOptimalSettingsCallback;
			result = NVSDK_NGX_Result_Success;
			break;
		case Util::NvParameter::DLSSGetStatsCallback:
			*OutValue = NVSDK_NGX_DLSS_GetStatsCallback;
			result = NVSDK_NGX_Result_Success;
			break;
		default:
			BadThingHappened();
			result = NVSDK_NGX_Result_Fail;
			break;
		}
		return result;
	}

	void NvParameter::Reset()
	{

	}

	// EvaluateRenderScale helper
	inline float DLSS2QualityTable(const NVSDK_NGX_PerfQuality_Value& input)
	{
		float output = NO_VALUEf;

		switch (input)
		{
		case NVSDK_NGX_PerfQuality_Value_UltraPerformance:
			output = 3.0f;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxPerf:
			output = 2.0f;
			break;
		case NVSDK_NGX_PerfQuality_Value_Balanced:
			output = 1.7f;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxQuality:
			output = 1.5f;
			break;
		case NVSDK_NGX_PerfQuality_Value_UltraQuality:
			output = 1.3f;
			break;
		}
		return output;
	}

	// EvaluateRenderScale helper
	inline FfxFsr2QualityMode DLSS2FSR2QualityTable(const NVSDK_NGX_PerfQuality_Value& input)
	{
		int output = NO_VALUEi;

		switch (input)
		{
		case NVSDK_NGX_PerfQuality_Value_UltraPerformance:
			output = FFX_FSR2_QUALITY_MODE_ULTRA_PERFORMANCE;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxPerf:
			output = FFX_FSR2_QUALITY_MODE_PERFORMANCE;
			break;
		case NVSDK_NGX_PerfQuality_Value_Balanced:
			output = FFX_FSR2_QUALITY_MODE_BALANCED;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxQuality:
			output = FFX_FSR2_QUALITY_MODE_QUALITY;
			break;
		case NVSDK_NGX_PerfQuality_Value_UltraQuality:
			//BadThingHappened();
			break;
		}
		return (FfxFsr2QualityMode)output;
	}

	// EvaluateRenderScale helper
	inline float GetQualityOverrideRatio(const NVSDK_NGX_PerfQuality_Value& input, const std::shared_ptr<Config>& config)
	{
		float output = 0;

		switch (input)
		{
		case NVSDK_NGX_PerfQuality_Value_UltraPerformance:
			output = config->Divisor_UltraPerformance;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxPerf:
			output = config->Divisor_Performance;
			break;
		case NVSDK_NGX_PerfQuality_Value_Balanced:
			output = config->Divisor_Balanced;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxQuality:
			output = config->Divisor_Quality;
			break;
		case NVSDK_NGX_PerfQuality_Value_UltraQuality:
			output = config->Divisor_UltraQuality;
			break;
		default:
			BadThingHappened();
			// no correlated value, add some logging?
			break;
		}
		if (output == 0)
			output = NO_VALUEf;
		return output;
	}

	inline ScreenDimensions GetFixedResFromQuality(const NVSDK_NGX_PerfQuality_Value& input, const std::shared_ptr<Config>& config)
	{

	}

	inline ScreenDimensions CalcSame(const auto& Width, const auto& Height, const auto& Division_Ratio) 
	{
		// Multiply is way faster than divide, do a single divide now to avoid it later
		const auto resolution_Ratio = 1.0f / Division_Ratio;
		ScreenDimensions output;
		output.first = std::lround(Width * resolution_Ratio);
		output.second = std::lround(Height * resolution_Ratio);
		return output;
	}

	inline ScreenDimensions CalcDifferent(const auto& Width, const auto& Height, const auto& Width_Division_Ratio, const auto& Height_Division_Ratio) 
	{
		ScreenDimensions output;
		output.first = std::lround(Width / Width_Division_Ratio);
		output.second = std::lround(Height / Height_Division_Ratio);
		return output;
	}

	inline ScreenDimensions DynaResProfile(const std::shared_ptr<Config>& InConfig, const NvParameter& InNvParameter) 
	{
		ScreenDimensions output;
		// TODO
		return output;
	}

	inline ScreenDimensions FixedResProfile(const std::shared_ptr<Config>& InConfig, const NvParameter& InNvParameter) 
	{
		ScreenDimensions output;

		switch (InNvParameter.PerfQualityValue)
		{
		case NVSDK_NGX_PerfQuality_Value_UltraPerformance:
			output = InConfig->Resolution_UltraPerformance;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxPerf:
			output = InConfig->Resolution_Performance;
			break;
		case NVSDK_NGX_PerfQuality_Value_Balanced:
			output = InConfig->Resolution_Balanced;
			break;
		case NVSDK_NGX_PerfQuality_Value_MaxQuality:
			output = InConfig->Resolution_Quality;
			break;
		case NVSDK_NGX_PerfQuality_Value_UltraQuality:
			output = InConfig->Resolution_UltraQuality;
			break;
		default:
			BadThingHappened();
			// no correlated value, add some logging?
			break;
		}
		return output;
	}

	inline ScreenDimensions DLSS2Profile(const std::shared_ptr<Config>& InConfig, const NvParameter& InNvParameter) 
	{
		ScreenDimensions output;

		float QualityRatio = GetQualityOverrideRatio(InNvParameter.PerfQualityValue, InConfig);

		if (QualityRatio == NO_VALUEf)
			QualityRatio = DLSS2QualityTable(InNvParameter.PerfQualityValue);

		output = CalcSame(InNvParameter.Width, InNvParameter.Height, QualityRatio);

		return output;
	}

	inline ScreenDimensions FSR2Profile(const std::shared_ptr<Config>& InConfig, const NvParameter& InNvParameter) 
	{
		ScreenDimensions output;

		float QualityRatio = GetQualityOverrideRatio(InNvParameter.PerfQualityValue, InConfig);

		if (QualityRatio == NO_VALUEf)
		{
			FfxFsr2QualityMode fsrQualityMode = DLSS2FSR2QualityTable(InNvParameter.PerfQualityValue);

			if (fsrQualityMode != NO_VALUEi)
			{
				const FfxErrorCode err = ffxFsr2GetRenderResolutionFromQualityMode(&output.first, &output.second, InNvParameter->Width, InNvParameter->Height, fsrQualityMode);
#ifdef _DEBUG
				switch (err)
				{
				case FFX_OK:
					// all good!
				BadThingHappened();
					break;
				case FFX_ERROR_INVALID_POINTER:
					//printf("EvaluateRenderScale error: FFX_ERROR_INVALID_POINTER");
				BadThingHappened();
					break;
				case FFX_ERROR_INVALID_ENUM:
					//printf("EvaluateRenderScale error: FFX_ERROR_INVALID_ENUM");
				BadThingHappened();
					break;
				default:
					//printf("EvaluateRenderScale error: default");
					// bad crap!
				BadThingHappened();
					break;
				}
#endif
			}
		}
		else
			output = CalcSame(InNvParameter.Width, InNvParameter.Height, QualityRatio);

		return output;
	}

	inline ScreenDimensions Switcher(const std::shared_ptr<Config>& InConfig, const NvParameter& InNvParameter, const UpscalingProfile& InProfile)
	{
		ScreenDimensions output;

		switch (InProfile)
		{
			case UpscalingProfile::DLSS2:
				output = DLSS2Profile(InConfig, InNvParameter);
				break;
			case UpscalingProfile::FSR2:
				output = FSR2Profile(InConfig, InNvParameter);
				break;
			case UpscalingProfile::DynaRes:
				output = DynaResProfile(InConfig, InNvParameter);
				break;
			case UpscalingProfile::FixedRes:
				output = FixedResProfile(InConfig, InNvParameter);
				break;
			default:
				BadThingHappened();
				// no correlated value, add some logging?
				break;
		}
		return output;
	}

	void NvParameter::EvaluateRenderScale()
	{
		const std::shared_ptr<Config> config = CyberFsrContext::instance()->MyConfig;

		const ScreenDimensions ScreenOrWindowDimension = {Width, Height};

		auto dimensions = Switcher(config, *this, config->UpscalerProfile);

		if (dimensions.first == 0 || dimensions.second == 0) {
			static const float defaultRatioVertical = 2.0f;
			static const float defaultRatioHorizontal = 2.0f;

			dimensions = CalcSame(ScreenOrWindowDimension.first, ScreenOrWindowDimension.second, defaultRatioVertical);
			//CalcDifferent(dimensions.Width, dimensions.Height, defaultRatioVertical, defaultRatioHorizontal);
		}
		//Width = ScreenOrWindowDimension.first;
		//Height = ScreenOrWindowDimension.second;
		//Width = dimensions.first;
		//Height = dimensions.second;

		//OutWidth = ScreenOrWindowDimension.first;
		//OutHeight = ScreenOrWindowDimension.second;
		OutWidth = dimensions.first;
		OutHeight = dimensions.second;

		Max_Render_Width = dimensions.first;
		Max_Render_Height = dimensions.second;
		//Max_Render_Width = dimensions.first;
		//Max_Render_Height = dimensions.second;

		//RenderWidth = Width;
		//RenderHeight = Height;

		Min_Render_Width = ScreenOrWindowDimension.first / 8;
		Min_Render_Height = ScreenOrWindowDimension.second / 8;

		Render_Subrect_Dimensions_Width = 64;
		Render_Subrect_Dimensions_Height = 64;

		EnableDynamicResolution = true;
		FrameTimeDeltaInMsec = (double) 6.7f;
	}


	namespace ParameterRepository 
	{
		constexpr UINT Size = 1024;
		Error_Resilient_Boolean Parameter_In_Use_Bool[Size] = {};
		NvParameter Parameters[Size] = {};
	};

	NvParameter* NvParameter::GetFreshParameter()
	{
		NvParameter* output = nullptr;

		for (int i = 0; i < ParameterRepository::Size && output == nullptr; i++) {
			const Error_Resilient_Boolean sanitizedBool = Sanitize_Bool(ParameterRepository::Parameter_In_Use_Bool[i]);
			switch (sanitizedBool)
			{
			case Error_Resilient_Boolean::ER_FALSE:
				ParameterRepository::Parameter_In_Use_Bool[i] = Error_Resilient_Boolean::ER_TRUE;
				output = &ParameterRepository::Parameters[i];
				break;
			case Error_Resilient_Boolean::ER_TRUE:
				BadThingHappened();
				break;
			case Error_Resilient_Boolean::Unknown:
				// bad thing, ram corruption or bad code?
				BadThingHappened();
				break;
			default:
				break;
			}
		}
		return output;
	}

	inline bool IsNvParamInternal(NvParameter* const& pointer)
	{
		const long long offset = pointer - ParameterRepository::Parameters;
		return offset < ParameterRepository::Size && pointer >= ParameterRepository::Parameters;
	}

	inline ULONGLONG GetIndex(NvParameter*& recyclePointer) {
		return (recyclePointer - ParameterRepository::Parameters) / (sizeof(NvParameter) * 8);
	}
	
	NvParameter* NvParameter::GetFreshCapabilityParameter() {
		const std::shared_ptr<Config> config = CyberFsrContext::instance()->MyConfig;

		NvParameter* const output = GetFreshParameter();
		if (output != nullptr)
		{
			output->RTXValue = NVSDK_NGX_RTX_Value_On;
			if(output->Width && output->Height)
				output->EvaluateRenderScale();
			else
			{
				output->OutWidth = 3840;
				output->OutHeight = 2160;
				output->Width = 800;
				output->Height = 450;
				output->Max_Render_Width = 800;
				output->Max_Render_Height = 450;
				output->Min_Render_Width = 320;
				output->Min_Render_Height = 180;
				//output->RenderWidth = output->Width;
				//output->RenderHeight = output->Height;
			}
			output->EnableSharpening = (*config).EnableSharpening.value_or(true);
			output->AutoExposure = true;
			output->Hdr = (*config).HDR.value_or(false);
			output->LowRes = false;
			output->OptLevel = NVSDK_NGX_OPT_LEVEL_RELEASE;
			output->IsDevSnippetBranch = 0;
			output->SuperSampling_Available = true;
		}
		return output;
	}

	void NvParameter::RecycleParameter(NvParameter* recyclePointer)
	{
		if (IsNvParamInternal(recyclePointer))
		{
			const ULONGLONG index = GetIndex(recyclePointer);
			Error_Resilient_Boolean& inUse = ParameterRepository::Parameter_In_Use_Bool[index];
			if (inUse != Error_Resilient_Boolean::ER_TRUE)
			{
				// bad thing happened, memory corruption?
				BadThingHappened();
			}
			inUse = Error_Resilient_Boolean::ER_FALSE;
			NvParameter& param = ParameterRepository::Parameters[index];
			param = {};
		}
		else
		{
			BadThingHappened();
			// throw bad shit happening code here
			//DebugBreak();
			return;
		}
	}

	NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_DLSS_GetOptimalSettingsCallback(NVSDK_NGX_Parameter* InParams)
	{
		if (IsNvParamInternal((NvParameter*)InParams))
		{
			NvParameter& params = *(NvParameter*)InParams;
			params.EvaluateRenderScale();
			return NVSDK_NGX_Result_Success;
		}
		else
		{
			BadThingHappened();
			return NVSDK_NGX_Result_Fail;
		}
	}

	NVSDK_NGX_Result NVSDK_CONV NVSDK_NGX_DLSS_GetStatsCallback(NVSDK_NGX_Parameter* InParams)
	{
		if (IsNvParamInternal((NvParameter*)InParams))
		{
			NvParameter& castedRef = *(NvParameter*)InParams;
			//Somehow check for allocated memory
			//Then set values: SizeInBytes, OptLevel, IsDevSnippetBranch

			castedRef.OptLevel = NVSDK_NGX_OPT_LEVEL_DEVELOP;
			castedRef.IsDevSnippetBranch = 0;
			castedRef.SizeInBytes = 0x1337;

			return NVSDK_NGX_Result_Success;
		}
		else
		{
			BadThingHappened();
			return NVSDK_NGX_Result_Fail;
		}

	}
}