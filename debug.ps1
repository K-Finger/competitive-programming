# Debug Build - sanitizers enabled
param(
    [Parameter(Mandatory=$true)]
    [string]$Source,
    [string]$Input = "input.txt"
)

$Name = [System.IO.Path]::GetFileNameWithoutExtension($Source)
$Exe = "$Name.exe"

$CompileArgs = @(
    "-std=c++20",
    "-g",
    "-O0",
    "-Wall",
    "-Wextra",
    "-Wshadow",
    "-D_GLIBCXX_DEBUG",
    "-DLOCAL",
    "-o", $Exe,
    $Source
)

Write-Host "Debug compiling $Source..." -ForegroundColor Yellow
g++ @CompileArgs

if ($LASTEXITCODE -eq 0) {
    Write-Host "Running $Exe..." -ForegroundColor Green
    if (Test-Path $Input) {
        Get-Content $Input | & ".\$Exe"
    } else {
        & ".\$Exe"
    }
}
