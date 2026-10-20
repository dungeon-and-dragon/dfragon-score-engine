# dfragon-score-engine

DFragon Desktop이 장비점수, 버프점수를 계산할 때 쓰는 네이티브 점수 엔진 바이너리입니다.
dfragon 저장소가 `packages/models/score-engine` submodule로 특정 커밋을 고정해 빌드에 넣습니다.
소스와 빌드는 비공개 엔진 저장소에 있고 이 저장소에는 Release 산출물만 둡니다.

| 파일 | 내용 | SHA256 |
| --- | --- | --- |
| `dnfscore.dll` | Windows x64(배포용) | `ec933638f17d09054855cd1ee7abb3f907e8c7ee4b895443e9c683c905f44b78` |
| `libdnfscore.dylib` | macOS arm64(개발 실행용) | `6d842f48a9bf7f57b7b6a0e26133fb64fbbce375fd43e79cebdc3e373b7d8ea2` |
| `dnfscore.h` | C ABI 헤더 | |
| `VERSION.json` | 엔진 버전, 규칙, 번들 식별자 | |

현재 파일은 엔진 Release `native-v0.3.0`의 자산 `dnfscore-0.3.0-win-x64.dll`, `libdnfscore-0.3.0-darwin-arm64.dylib`을 이름만 바꿔 넣은 것입니다.
규칙은 rev14(번들 `phase32-rev14`)입니다.
`dnfscore.h`, `VERSION.json`은 Release 자산 그대로입니다.

## 갱신

1. 엔진 저장소에서 새 `native-v<버전>` Release를 받고 Release의 `.sha256`과 대조합니다.
2. 위 이름으로 바꿔 이 저장소에 커밋하고, 이 README의 버전과 SHA256을 고칩니다.
3. dfragon에서 submodule을 그 커밋으로 옮기는 PR을 냅니다. 이 저장소에 올리는 것만으로 Desktop 빌드는 바뀌지 않습니다.
