param(
    [string]$BuildDir = "build-windows",
    [string]$Generator = "Ninja",
    [string]$Config = "Release"
)

if (-not (Test-Path $BuildDir)) {
    New-Item -ItemType Directory -Path $BuildDir | Out-Null
}

cmake -S . -B $BuildDir -G $Generator `
    -DCMAKE_BUILD_TYPE=$Config `
    $(if ($env:QT_PREFIX_PATH) { "-DCMAKE_PREFIX_PATH=$($env:QT_PREFIX_PATH)" } )

cmake --build $BuildDir --config $Config


