# HCM_CDE_L946

## 简介

这是HCM降本版L946项目。

## 配置编译环境和编辑环境

### 编辑环境

工程默认的编辑环境为VSCODE，可自行选择编辑环境，但请勿上传编辑环境带来的文件，使用.gitignore文件来排除这些内容。

下面将针对VSCODE下如何添加头文件等内容作说明。需要下载插件：

- [ ] [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

- [ ] [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)

- [ ] [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes)

- [ ] [Git Graph](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)

其他插件功能可自行定义。

### 下载工程

1. 回到该页面顶部，点击该页面上方克隆按钮，选择“使用HTTP克隆”。

1. 返回VSCODE，点击左侧导航栏的“源代码管理”(快捷键Ctrl+Shift+G), 点击“克隆仓库”，将地址填入导航栏，回车，选择代码存放位置。

1. 好了，开始享受代码人生 :D

### 配置编译环境

新建的代码文件需要在VSCODE中添加头文件。点击扩展的C/C++设置，切换到扩展在该文件夹设置，寻找设置项：C_Cpp › Default: Include Path，添加新的include文件夹即可。或直接在.setting中输入，请注意输入的内容要符合JSON语法，否则将造成多插件的配置错误。
推荐使用直接在.setting中添加的方法，方便快捷，但切记新加行要加逗号！！

### 配置编译环境1

- [ ] 抓取项目文件后，请打开makefile文件夹，新建名称为env.mk的文件，输入如下内容并将地址路径改为自己的路径。

    ```text
    GHS_DIR = D:/ghs/comp_202114
    ```

- [ ] 打开sourcedir.mk添加对应SRC_DIR以及INCLUDE_DIR，以添加自己新增的源码文件和头文件（MCAL模块的文件无需在此添加）。
- [ ] 下载w64devkit-1.20.0或更高版本，解压，并将子文件夹bin设置为系统环境变量路径，重启VSCODE。
- [ ] 使用VSCODE的终端(快捷键Ctrl+Shift+`)进入工程根目录下的makefile文件夹。

    ```cmd
    cd makefile
    ```

- [ ] 输入make build或 make 来启动编译。

    ```cmd
    make build
    ```

    ```cmd
    make
    ```

- [ ] 输入make clean来清除编译目录和生成内容

    ```cmd
    make clean
    ```

## 添加文件

- [ ] 使用Git指令上传文件
- [ ] [添加文件使用命令行](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) 或推送(使用第三方图形界面体验更加):
- [ ] 使用VSCODE自带的git功能来拉取更新，可下载Git Graph插件来辅助多数操作

    ```cmd
    cd existing_repo
    git remote add origin http://172.16.245.59/hcm-cost-descending-edition/hcm_cde_l946.git
    git branch -M main
    git push -uf origin main
    ```

## 设置集成

- [ ] [设置项目集成(暂不支持)](http://172.16.245.59/hcm-cost-descending-edition/hcm_cde_l946/-/settings/integrations)

## 与你的团队合作

- [ ] [邀请团队成员和合作者](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [新建合并请求](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [自动关闭问题点(暂不支持)](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [开启合并请求](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)

## 测试与部署

使用GitLab集成的工具进行测试和部署(暂不支持).

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing(SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***
