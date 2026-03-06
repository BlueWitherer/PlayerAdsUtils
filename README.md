# [<img src="https://github.com/DumbCaveSpider/PlayerAdvertisements/blob/nightly/logo.png?raw=true" width="25" alt="The mod's logo." />](https://www.geode-sdk.org/mods/cheeseworks.moddevbranding) Player Advertisements
Community-made ads for awesome levels!

> [![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/W7W31QRZA4)

## Development
Let's start this off by adding this library as a CPM package in your `CMakeLists.txt`!
```cmake
CPMAddPackage("gh:BlueWitherer/PlayerAdsUtils@1.0.0") # or master for latest commit
target_link_libraries(${PROJECT_NAME} PlayerAdsUtils)
```

You can access all utilities in this library by including [`Include.hpp`](include/PlayerAdsUtils/Include.hpp) in your code. Make sure to use the `ads` namespace to directly access all the needed classes.
```cpp
#include <PlayerAdsUtils/Include.hpp>

using namespace ads;
```

### Creating Ads
To create an ad node, simply do the following.
```cpp
auto ad = Advertisement::create();
```

You can also assign it a type for different sizing.
```cpp
auto ad = Advertisement::create(AdType::Square);
```