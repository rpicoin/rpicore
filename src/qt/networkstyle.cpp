// Copyright (c) 2014 The Bitcoin developers
// Copyright (c) 2017-2018 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "networkstyle.h"

#include "guiconstants.h"

#include <QApplication>
#include <utility>

static const struct {
    const char* networkId;
    const char* appName;
    const char* appIcon;
    const char* titleAddText;
    const char* splashImage;
} network_styles[] = {
    {"main", QAPP_APP_NAME_DEFAULT, ":/icons/bitcoin", "", ":/images/splash"},
    {"test", QAPP_APP_NAME_TESTNET, ":/icons/bitcoin_testnet", QT_TRANSLATE_NOOP("SplashScreen", "[testnet]"), ":/images/splash_testnet"},
    {"regtest", QAPP_APP_NAME_TESTNET, ":/icons/bitcoin_regtest", "[regtest]", ":/images/splash_regtest"}};
static const unsigned network_styles_count = sizeof(network_styles) / sizeof(*network_styles);

// titleAddText needs to be const char* for tr()
NetworkStyle::NetworkStyle(QString  appName, const QString& appIcon, const char* titleAddText, const QString& splashImage) : appName(std::move(appName)),
                                                                                                                                   appIcon(appIcon),
                                                                                                                                   titleAddText(qApp->translate("SplashScreen", titleAddText)),
                                                                                                                                   splashImage(splashImage)
{
}

const NetworkStyle* NetworkStyle::instantiate(const QString& networkId)
{
    for (const auto & network_style : network_styles) {
        if (networkId == network_style.networkId) {
            return new NetworkStyle(
                network_style.appName,
                network_style.appIcon,
                network_style.titleAddText,
                network_style.splashImage);
        }
    }
    return nullptr;
}
