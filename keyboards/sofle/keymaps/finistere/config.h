#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options. */

// Delay before choosing "Hold" instead of "Tap"
#define TAPPING_TERM 200
// If another key is tapped while holding the key, it's "Hold" whether the delay expired or not.
#define PERMISSIVE_HOLD

// For Link Time Optimization (-flto)
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
