# Competitive Programming Quick Build/Run Script
# Usage: ./run.ps1 solution.cpp [input.txt]

param(
    [Parameter(Mandatory=$true)]
    [string]$Source,
    [string]$Input = "input.txt"
)

$Name = [System.IO.Path]::GetFileNameWithoutExtension($Source)
$Exe = "$Name.exe"

# Compile with optimizations and warnings
$CompileArgs = @(
    "-std=c++20",
    "-O2",
    "-Wall",
    "-Wextra",
    "-Wshadow",
    "-o", $Exe,
    $Source
)

Write-Host "Compiling $Source..." -ForegroundColor Cyan
g++ @CompileArgs

if ($LASTEXITCODE -eq 0) {
    Write-Host "Running $Exe..." -ForegroundColor Green
    if (Test-Path $Input) {
        Get-Content $Input | & ".\$Exe"
    } else {
        & ".\$Exe"
    }
    Remove-Item $Exe -ErrorAction SilentlyContinue
} else {
    Write-Host "Compilation failed!" -ForegroundColor Red
}
