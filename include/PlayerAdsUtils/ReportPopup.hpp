#pragma once

#include <cocos2d.h>

#include <Geode/Geode.hpp>

namespace ads {
    class ReportPopup final : public geode::Popup {
    private:
        class Impl;
        std::unique_ptr<Impl> m_impl;

    protected:
        ReportPopup();
        ~ReportPopup();

        bool init(unsigned int adId, int levelId, std::string description);
        void onSubmitButton(cocos2d::CCObject* sender);

    public:
        static ReportPopup* create(unsigned int adId, int levelId, std::string description);
    };
};