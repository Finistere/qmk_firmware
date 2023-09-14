Configure default keyboard:
```sh
qmk config user.keyboard=sofle/rev1 user.keymap=finistere

# switch side between flashes
qmk compile && qmk flash && qmk flash

# test keys
showkey -a
```
