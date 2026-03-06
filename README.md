# [<img src="https://github.com/DumbCaveSpider/PlayerAdvertisements/blob/nightly/logo.png?raw=true" width="25" alt="The mod's logo." />](https://www.geode-sdk.org/mods/arcticwoof.player_advertisements) Player Advertisements
Community-made ads for awesome levels!

> [![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/W7W31QRZA4)

## Development
Let's start off by adding this library as a CPM package in your `CMakeLists.txt`!
```cmake
CPMAddPackage("gh:BlueWitherer/PlayerAdsUtils@1.0.1") # or "#master" for latest commit
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

#### Tracking Engagement
These ads can track clicks and views. By default, this behavior is **disabled**. You can choose to enable it by setting the **`PAU_TRACK_STATS`** configuration option to `ON`.

```cmake
set(PAU_TRACK_STATS ON)
```

We normally would **not recommend you use this on your mod** unless it is intended for the Geode index and you simply wish to add a compatibility feature for [Player Advertisements](https://www.geode-sdk.org/mods/arcticwoof.player_advertisements) on your own layers and pop-ups.

> [!WARNING]
> Abuse of this feature **will result in ratelimiting or IP banning from the advertisements server**.