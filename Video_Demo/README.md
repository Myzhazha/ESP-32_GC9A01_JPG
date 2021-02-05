此Demo参考https://github.com/moononournation/RGB565_video

此Demo使用FFmpeg转换视频为.mjpeg，FFmpeg下载地址https://ffmpeg.org

使用方法：
把视频用剪辑软件修改分辨率为240x240，并导出为.mp4格式
下载FFmpeg使用命令行工具执行以下命令

`
ffmpeg -i [你的mp4文件路径] -vf "fps=30,scale=-1:176:flags=lanczos,crop=220:in_h:(in_w-220)/2:0" -q:v 9 [输出路径]
如：ffmpeg -i D:\video\1.mp4 -vf "fps=30,scale=-1:176:flags=lanczos,crop=220:in_h:(in_w-220)/2:0" -q:v 9 D:\video\240_30fps.mjpeg
`

转换完成后把240_30fps.mjpeg文件放到TF卡根目录即可