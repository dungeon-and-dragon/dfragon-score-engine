# dfragon-score-engine

DFragon Desktop이 장비점수, 버프점수를 계산할 때 쓰는 네이티브 점수 엔진 바이너리입니다.
dfragon 저장소가 `packages/models/score-engine` submodule로 특정 커밋을 고정해 빌드에 넣습니다.
소스와 빌드는 비공개 엔진 저장소에 있고 이 저장소에는 Release 산출물만 둡니다.

| 파일 | 내용 | SHA256 |
| --- | --- | --- |
| `dnfscore.dll` | Windows x64(배포용) | `9dc10ce4a0ae80bc8c24716e4a70104530cebde2dd1befe33fa70f6eb82f4e60` |
| `libdnfscore.dylib` | macOS arm64(개발 실행용) | `57eb3d437efb3019030ce2dde7d2cb79266091a3fe5cca7f274c63192d0d6c78` |

Desktop의 `score-engine.config.mjs`가 플랫폼별로 위 두 파일만 복사합니다.
C ABI 헤더(`dnfscore.h`)와 버전 정보(`VERSION.json`)는 Desktop이 읽지 않아 두지 않습니다.
필요하면 엔진 Release 자산이나 엔진 저장소에서 봅니다.

`dnfscore.dll`은 엔진 0.4.2(엔진 저장소 main `483a3fa0`)를 로컬에서 `x86_64-pc-windows-msvc`로 빌드한 것입니다.
0.4.2는 아직 엔진 Release가 없습니다.
Windows 엔진의 규칙은 rev14(번들 `phase32-rev14d`)입니다.
`libdnfscore.dylib`은 아직 `native-v0.3.1`(규칙 rev14, 번들 `phase32-rev14b`)의 자산입니다.
0.4.x의 macOS 자산은 나중에 추가합니다.

## 갱신

1. 엔진 저장소에서 새 `native-v<버전>` Release를 받고 Release의 `.sha256`과 대조합니다.
2. 위 이름으로 바꿔 이 저장소에 커밋하고, 이 README의 버전과 SHA256을 고칩니다.
3. dfragon에서 submodule을 그 커밋으로 옮기는 PR을 냅니다. 이 저장소에 올리는 것만으로 Desktop 빌드는 바뀌지 않습니다.
