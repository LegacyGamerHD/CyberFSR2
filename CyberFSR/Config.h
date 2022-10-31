#pragma once
#include "pch.h"

enum class SharpnessRangeModifier
{
	Normal,
	Extended,
};

enum class ViewMethod
{
	Config,
	Cyberpunk2077,
	RDR2,
};

enum class UpscalingProfile
{
	FSR2,
	DLSS2,
	DynaRes,
	Fixed
};

// String switch paridgam

struct SharpnessRangeModifierMap : public std::map<std::string, SharpnessRangeModifier>
{
	SharpnessRangeModifierMap()
	{
		this->operator[]("Normal") = SharpnessRangeModifier::Normal;
		this->operator[]("Extended") = SharpnessRangeModifier::Extended;
	};
	~SharpnessRangeModifierMap() {}
};

struct ViewMethodMap : public std::map<std::string, ViewMethod>
{
	ViewMethodMap()
	{
		this->operator[]("Config") = ViewMethod::Config;
		this->operator[]("Cyberpunk2077") = ViewMethod::Cyberpunk2077;
		this->operator[]("RDR2") = ViewMethod::RDR2;
	};
	~ViewMethodMap() {}
};

struct UpscalingProfileMap : public std::map<std::string, UpscalingProfile>
{
	UpscalingProfileMap()
	{
		this->operator[]("FSR2") = UpscalingProfile::FSR2;
		this->operator[]("DLSS2") = UpscalingProfile::DLSS2;
		this->operator[]("DynaRes") = UpscalingProfile::DynaRes;
		this->operator[]("Fixed") = UpscalingProfile::Fixed;
	};
	~UpscalingProfileMap() {}
};

class Config
{
public:
	Config(std::string fileName);

	// Depth
	std::optional<bool> DepthInverted;

	// Color
	std::optional<bool> AutoExposure;
	std::optional<bool> HDR;

	// Motion
	std::optional<bool> JitterCancellation;
	std::optional<bool> DisplayResolution;

	// Sharpening
	std::optional<bool> EnableSharpening;
	std::optional<float> Sharpness;
	std::optional<SharpnessRangeModifier> SharpnessRange;

	// Dynamic Scaler
	std::optional<bool> DynamicScalerEnabled;
	std::optional<float> FPSTarget;
	std::optional<float> FPSTargetMin;
	std::optional<float> FPSTargetMax;
	std::optional<float> FPSTargetResolutionMin;
	std::optional<float> FPSTargetResolutionMax;

	// View
	std::optional<ViewMethod> ViewHookMethod;
	std::optional<float> VerticalFOV;
	std::optional<float> NearPlane;
	std::optional<float> FarPlane;
	std::optional<bool> InfiniteFarPlane;

	// Hotfix for Steam Deck
	std::optional<bool> DisableReactiveMask;

	// Sharpening
	std::optional<bool> EnableSharpening;
	std::optional<float> Sharpness;
	std::optional<SharpnessRangeModifier> SharpnessRange;

	// Upscale type
	std::optional<UpscalingProfile> UpscalerProfile;

	// Quality Overrides
	std::optional<float> QualityRatio_UltraQuality;
	std::optional<float> QualityRatio_Quality;
	std::optional<float> QualityRatio_Balanced;
	std::optional<float> QualityRatio_Performance;
	std::optional<float> QualityRatio_UltraPerformance;

	//  Render Resolution Overrides
	std::optional<std::pair<unsigned int, unsigned int>> QualityResolution_UltraQuality;
	std::optional<std::pair<unsigned int, unsigned int>> QualityResolution_Quality;
	std::optional<std::pair<unsigned int, unsigned int>> QualityResolution_Balanced;
	std::optional<std::pair<unsigned int, unsigned int>> QualityResolution_Performance;
	std::optional<std::pair<unsigned int, unsigned int>> QualityResolution_UltraPerformance;

	void Reload();

private:
	CSimpleIniA ini;

	std::filesystem::path absoluteFileName;

	std::optional<std::string> readString(std::string section, std::string key, bool lowercase = false);
	std::optional<float> readFloat(std::string section, std::string key);
	std::optional<bool> readBool(std::string section, std::string key);
	std::optional<SharpnessRangeModifier> readSharpnessRange(std::string section, std::string key);
	std::optional<ViewMethod> readViewMethod(std::string section, std::string key);
	//std::optional<UpscalingProfile> readUpscalingProfile(std::string section, std::string key);
};