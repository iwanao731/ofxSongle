# ofxSongle

産総研が開発した音楽解析API SongleのoF用のアドオンです。

Youtubeやニコニコ動画のURLを入力すると、その動画に含まれる音楽の解析済み結果をJSON形式で取得することができます。なお、取得できる情報は
  * 楽曲の基本情報(タイトル等)
  * ビート
  * コード
  * メロディー
  * 繰り返し情報(楽曲構成)

※URLの動画がSongle側で事前に解析済みである必要があります。  
Songleに解析申請を行う等の情報は[Songle API Widget](https://widget.songle.jp/docs/v1)を御覧ください。

## 必要なアドオン
  [ofxJSON](https://github.com/jeffcrouse/ofxJSON)  
  [ofxTimecode](https://github.com/YCAMInterlab/ofxTimecode) (exampleにて)
