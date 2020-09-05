#ifndef MARKET_DATA_NASDAQ_NASDAQ_HPP_
#define MARKET_DATA_NASDAQ_NASDAQ_HPP_

#include <string>
#include <ctime>
#include <limits.h>
#include <curl/curl.h>
#include <fstream>
#include <vector>

#include "../../../include/json.hpp"

namespace market_data {
    namespace nasdaq {
        class RealTimeTrade {
        public:
            RealTimeTrade() = default;
            RealTimeTrade(const std::string &time, const std::string &price, const std::string &shareVolume) {}

            std::string time;
            std::string price;
            std::string shareVolume;
        };

        namespace {
            inline std::string formatUrl(const std::string &symbol, const std::string &time, int limit);
        }

        inline size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

        void to_json(nlohmann::json& j, const RealTimeTrade& p);

        void from_json(const nlohmann::json& j, RealTimeTrade& p);

        std::vector<RealTimeTrade> getRealTimeTrades(const std::string &symbol, std::string time, int limit = INT_MAX);
    }
}

#endif