# 3 step build process

## Step 1. delete old build folder
```rm -rf build```

## Step 2. configure project

### reads cmakelists.txt and sets up build environment
```cmake -B build```

### if cmake path error, specify path locally...AND RUN IN SYSTEM TERMINAL
```
    cd ~/Code/cpp_basics/3_webview_vuejs
    rm -rf build
    cmake -B build -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu
    cmake --build build
```

## Step 3. Run executable

```./build/ExpenseEntryApp```