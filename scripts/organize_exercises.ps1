param(
    [switch]$DryRun
)

$root = Join-Path $PSScriptRoot "..\exercises"
$root = (Resolve-Path $root).Path

Write-Host "Root exercices : $root" -ForegroundColor Cyan

Get-ChildItem -Path $root -Filter "ex*.cpp" -File | ForEach-Object {
    $file = $_
    if ($file.Name -match '^ex(\d+)_?(.*)\.cpp$') {
        $num = $matches[1]
        $rest = $matches[2] -replace '\\.', '_' -replace '\\s+','_'
        if ([string]::IsNullOrEmpty($rest)) { $folderName = "ex$($num)" } else { $folderName = "ex$($num)_$($rest)" }
        $targetDir = Join-Path $root $folderName

        if (-not (Test-Path $targetDir)) {
            if ($DryRun) { Write-Host "DRYRUN: New directory -> $targetDir" -ForegroundColor Yellow } else { New-Item -Path $targetDir -ItemType Directory | Out-Null }
        }

        $dest = Join-Path $targetDir "exercise.cpp"
        if ($DryRun) {
            Write-Host "DRYRUN: Move: $($file.FullName) -> $dest" -ForegroundColor Yellow
        } else {
            Move-Item -Path $file.FullName -Destination $dest -Force
            Write-Host "Moved $($file.Name) -> $folderName/exercise.cpp" -ForegroundColor Green
        }

        # Solutions potentielles
        $solCandidates = Get-ChildItem -Path $root -File | Where-Object {
            $_.Name -ne $file.Name -and $_.Name -match ("^ex$($num).*") -and $_.Name -match "(?i)sol|solution|answer|reponse|réponse"
        }
        foreach ($s in $solCandidates) {
            $destSol = Join-Path $targetDir ("solution_" + $s.Name)
            if ($DryRun) {
                Write-Host "DRYRUN: Move solution: $($s.FullName) -> $destSol" -ForegroundColor Yellow
            } else {
                Move-Item -Path $s.FullName -Destination $destSol -Force
                Write-Host "Moved solution $($s.Name) -> $folderName/$(Split-Path $destSol -Leaf)" -ForegroundColor Magenta
            }
        }

        # README minimal
        $readme = Join-Path $targetDir "README.md"
        if (-not (Test-Path $readme)) {
            $content = @"
# $folderName

Fichiers :
- exercise.cpp -> enonce / zone d'implementation
- solution_*.cpp -> solutions (si presentes)

Instructions :
1. Implementer dans exercise.cpp
2. Compiler et tester
3. Commit apres validation
"@
            if ($DryRun) { Write-Host "DRYRUN: Create README -> $readme" -ForegroundColor Yellow } else { $content | Out-File -FilePath $readme -Encoding UTF8 }
        }
    }
}

Write-Host "Terminé. DryRun=$DryRun" -ForegroundColor Cyan
