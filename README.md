# CLITetrisBase
知人の[齊藤君](https://twitter.com/oshare_na_orc)の人生更生プログラムです

主にGame.cppのUpdateGame()とDrawGame()関数の中身をいじって  
コマンドラインベースのブロック落下パズルゲーム（テト○ス）を作ってください  
C言語ベース(ソースはcpp)ですが各自いい感じにやってください

# 必要環境
* Visual Studio 2015 以降

# 使用ライブラリ
* [cppconlib](https://archive.codeplex.com/?p=cppconlib)  
  > Copyright (c) Marius Bancila 2013  
  >               http://mariusbancila.ro  
  
  多重インクルードすると多重定義になってしまう関数があったのでstatic inline化して改変してます  
