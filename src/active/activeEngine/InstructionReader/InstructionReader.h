#pragma once
#include "../../activeConstants/constants.h"


namespace activeEngine {
    class InstructionReader :private activeConstants::Constants {
        // variables
    private:
        // functions
    private:
        void decrypt();
        nlohmann::json readFile(const std::string filename);
    protected:
        /*std::vector<const char*> instruction_reader::read_scene();

        {
    "renderPasses": [
        {
            "name": "mainRenderPass_v2",
            "attachments": [
                {
                    "type": "color",
                    "format": "VK_FORMAT_B8G8R8A8_SRGB",
                    "samples": "VK_SAMPLE_COUNT_1_BIT",
                    "loadOp": "VK_ATTACHMENT_LOAD_OP_CLEAR",
                    "storeOp": "VK_ATTACHMENT_STORE_OP_STORE",
                    "initialLayout": "VK_IMAGE_LAYOUT_UNDEFINED",
                    "finalLayout": "VK_IMAGE_LAYOUT_PRESENT_SRC_KHR"
                },
                {
                    "type": "depth",
                    "format": "VK_FORMAT_D32_SFLOAT",
                    "samples": "VK_SAMPLE_COUNT_1_BIT",
                    "loadOp": "VK_ATTACHMENT_LOAD_OP_CLEAR",
                    "storeOp": "VK_ATTACHMENT_STORE_OP_DONT_CARE",
                    "initialLayout": "VK_IMAGE_LAYOUT_UNDEFINED",
                    "finalLayout": "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL"
                }
            ]
        }
    ]
}


        VkFormat stringToVkFormat(const std::string& formatStr) {
            static std::unordered_map<std::string, VkFormat> formatMap = {
                {"VK_FORMAT_B8G8R8A8_SRGB", VK_FORMAT_B8G8R8A8_SRGB},
                {"VK_FORMAT_D32_SFLOAT", VK_FORMAT_D32_SFLOAT},
                // Add other formats as needed...
            };
            VkAttachmentDescription attachment{};
            attachment.format = stringToVkFormat(attachmentConfig["format"]);
            return formatMap[formatStr];
        }
        */
    };
}