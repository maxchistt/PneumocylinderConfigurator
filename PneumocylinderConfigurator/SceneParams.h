#pragma once
struct SceneParams {
	bool doubleSided = true;
	bool edges = false;
	int lightType = 1;
	bool section = false;
	bool frameVisble = false;
	std::vector<std::uint32_t> hideIndexes = std::vector<std::uint32_t>{ std::uint32_t("Pneumocylinder case") };
};