此Demo修改自https://github.com/moononournation/RGB565_video

此Demo使用FFmpeg转换视频为.mjpeg，FFmpeg下载地址https://ffmpeg.org

使用方法：
把视频用剪辑软件修改分辨率为240x240，并导出为.mp4格式  
下载FFmpeg并在FFmpeg.exe目录下按住shift键鼠标右键-在此处打开PowerShell窗口  

执行以下命令将mp4文件转换为mjpeg格式  

`
./ffmpeg -i [你的mp4文件路径] -vf "fps=30,scale=-1:240:flags=lanczos,crop=240:in_h:(in_w-240)/2:0" -q:v 9 [输出路径]
`  
  
比如：  
  
`
./ffmpeg -i D:\video\1.mp4 -vf "fps=30,scale=-1:240:flags=lanczos,crop=240:in_h:(in_w-240)/2:0" -q:v 9 D:\video\240_30fps.mjpeg
`

转换完成后把240_30fps.mjpeg文件放到TF卡根目录即可
