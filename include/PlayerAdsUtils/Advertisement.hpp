#pragma once

#include <memory>

#include <cocos2d.h>

#include <Geode/utils/web.hpp>

#include <Geode/ui/LazySprite.hpp>

namespace ads {
    namespace sizes {
        inline constexpr cocos2d::CCSize banner = { 364.f, 45.f };
        inline constexpr cocos2d::CCSize square = { 122.6f, 122.6f };
        inline constexpr cocos2d::CCSize skyscraper = { 41.f, 314.f };
    };

    namespace particles {
        inline constexpr auto banner = "1,2065,2,4515,3,855,155,1,156,20,145,20a-1a1a0.3a15a90a0a20a0a100a25a0a25a0a0a0a0a10a5a0a180a1a0a1a0a1a0a1a0a5a0a180a0a1a0a1a0a1a0a1a0a0a1a1a0a0a0a0a0a0a0a0a2a1a0a0a0a41a0a0a0a0a0a0a0a0a0a0a0a0a0a0;";
        inline constexpr auto square = "1,2065,2,4515,3,855,155,1,156,20,145,20a-1a1a0.3a15a90a0a20a0a50a50a0a25a0a0a0a0a10a5a0a180a1a0a1a0a1a0a1a0a5a0a180a0a1a0a1a0a1a0a1a0a0a1a1a0a0a0a0a0a0a0a0a2a1a0a0a0a41a0a0a0a0a0a0a0a0a0a0a0a0a0a0;";
        inline constexpr auto skyscraper = "1,2065,2,4515,3,855,155,1,156,20,145,20a-1a1a0.3a15a90a0a20a0a25a100a0a25a0a0a0a0a10a5a0a180a1a0a1a0a1a0a1a0a5a0a180a0a1a0a1a0a1a0a1a0a0a1a1a0a0a0a0a0a0a0a0a2a1a0a0a0a41a0a0a0a0a0a0a0a0a0a0a0a0a0a0;";
    };

    enum class AdType : unsigned int {
        Banner = 1,
        Square = 2,
        Skyscraper = 3
    };

    struct Ad final {
        unsigned int id;
        std::string image;
        int level = 0;
        std::string user = "";
        AdType type;
        int viewCount = 0;
        int clickCount = 0;
        int glowLevel = 0;

        Ad() = default;

        Ad(
            unsigned int id,
            std::string image,
            int level,
            AdType type,
            std::string user,
            int viewCount = 0,
            int clickCount = 0,
            int glowLevel = 0
        ) : id(id),
            image(std::move(image)),
            level(level),
            type(type),
            user(std::move(user)),
            viewCount(viewCount),
            clickCount(clickCount),
            glowLevel(glowLevel) {};
    };

    /**
     * Get the size of an ad based on its type
     * @param type The type of ad
     */
    constexpr cocos2d::CCSize getAdSize(AdType type);

    /**
     * Get the particle string based on an ad type
     * @param type The type of ad
     */
    constexpr const char* getParticlesForAdType(AdType type);

    class Advertisement final : public cocos2d::CCNode {
    private:
        class Impl;
        std::shared_ptr<Impl> m_impl;

        // Reloads the advertisement button
        void reload();

        // Reloads the type of advertisement
        void reloadType();

    protected:
        Advertisement();
        ~Advertisement();

        bool init(AdType type);

    public:
        /**
         * Create a new advertisement
         * @param type The type of ad to create
         */
        static Advertisement* create(AdType type = AdType::Banner);

        /**
         * Load a specific advertisement by its ID
         * @param id The ID of the ad to load
         * @warning This will override the current set type of ad
         */
        void load(int id);

        /**
         * Load a random advertisement
         */
        void loadRandom();

        /**
         * Get the LazySprite associated with the advertisement
         */
        [[nodiscard]] geode::LazySprite* getAdSprite() const;

        /**
         * Handle the response from the advertisement fetch request
         * @param res The web response containing the advertisement data
         */
        void handleAdResponse(geode::utils::web::WebResponse const& res);
    };
};