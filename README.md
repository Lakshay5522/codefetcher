# codefetcher (online code server)

Payload for the **codefetcher** CMD tool. The tool fetches a single program over
raw HTTPS and writes it into the user's current folder — nothing else is stored
on their machine.

## Layout
- `index.txt` — manifest, one line per program: `id|alias|lang|title|path|target`
- `ds/*.cpp` — 25 Data Structures programs (C++)
- `os/*.java` — 25 Operating Systems programs (Java)

## Raw base URL
```
https://raw.githubusercontent.com/Lakshay5522/codefetcher/main/
```

## Adding or editing a program
1. Add/overwrite the file under `ds/` or `os/` (Java: the class name should match
   the intended output file name, e.g. `class Fibonacci` -> `Fibonacci.java`).
2. Add/update its line in `index.txt`.
No rebuild of the tool is needed — it reads `index.txt` at run time.
