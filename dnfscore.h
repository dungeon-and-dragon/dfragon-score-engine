/* dnfscore 네이티브 라이브러리: 던전앤파이터 장비점수, 버프점수(rev12 규칙) 계산.
 *
 * 모든 문자열은 UTF-8이다. dnfscore_score가 채운 out_json은 dnfscore_free로 해제한다.
 * 반환 0이 성공이고 그 밖은 오류 코드이며 out_json에 {"error":{"code":"...","message":"..."}}를 담는다.
 * 건너뛰기(입력을 해석하지 못함)는 오류가 아니라 성공 결과의 score null, skipped {kind, message}다.
 * 동시 호출은 지원하지 않는다(준비물 초기화만 잠근다). */
#ifndef DNFSCORE_H
#define DNFSCORE_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#  if defined(DNFSCORE_BUILD)
#    define DNFSCORE_API __declspec(dllexport)
#  else
#    define DNFSCORE_API __declspec(dllimport)
#  endif
#elif defined(__GNUC__)
#  define DNFSCORE_API __attribute__((visibility("default")))
#else
#  define DNFSCORE_API
#endif

enum dnfscore_status {
    DNFSCORE_OK = 0,
    DNFSCORE_ERROR_INVALID_JSON = 1,            /* JSON 파싱 실패, 최상위가 객체가 아님 */
    DNFSCORE_ERROR_MISSING_DOCUMENT = 2,        /* 응답 10개 중 누락, 알 수 없는 문서 이름, status 식별 칸 누락 */
    DNFSCORE_ERROR_UNSUPPORTED_CALCULATOR = 3,  /* calculator가 "equipment", "buff", "auto"가 아님 */
    DNFSCORE_ERROR_INTERNAL = 4                 /* 블롭 손상, 메모리 부족, 분류되지 않은 내부 오류 */
};

/* {"package":"dnfscore-native <버전>","rules_rev":"rev12","bundle_id":"<번들 ID>","manifest_sha256":"<번들 MANIFEST.json sha256>"} 정적 문자열. 해제하지 않는다. */
DNFSCORE_API const char *dnfscore_version(void);

/* character_json: spec/schema/character.schema.json(Neople 응답 10개와 items) UTF-8, length 바이트.
 * calculator: "equipment" | "buff" | "auto"(CLI 규칙: jobName이 버퍼 직업이면 buff). 제품은 equipment 또는 buff를 지정한다.
 * out_json: result.schema.json 필드 + display {role, switchingLevel, buff30, buff50}. */
DNFSCORE_API int dnfscore_score(const char *character_json, size_t length, const char *calculator, char **out_json);

DNFSCORE_API void dnfscore_free(char *out_json);

#ifdef __cplusplus
}
#endif
#endif
