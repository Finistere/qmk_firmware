Configure default keyboard:
```sh
qmk config user.keyboard=sofle/rev1 user.keymap=finistere

qmk compile

# switch side
qmk flash && qmk flash
```
