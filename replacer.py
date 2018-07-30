import re
import os
import sys


class Replacer(object):

    username = "BlackCatSheriff"
    repository_name = "algorithm-exercises"
    branch = "master"

    def __init__(self,input_file):
        self._md_img_reg = re.compile('(!\[\w+\]\((.*)\))')
        self._input_file = input_file
        self._replace_pattern_prefix = "https://raw.githubusercontent.com/{username}/{repository_name}" \
                                "/{branch}/".format(username=self.username,
                                                    repository_name=self.repository_name, branch=self.branch)

    def __replace_img_path(self):
        text = self.__read_text()
        _base_dir = os.path.dirname(self._input_file)
        os.chdir(_base_dir)
        items = self._md_img_reg.findall(text)
        for it in items:
            _real_path = os.path.abspath(it[1])
            suffix =_real_path[_real_path.find(self.repository_name)+len(self.repository_name)+1:]
            tmp = it[0].replace(it[1], self._replace_pattern_prefix+suffix.replace('\\','/'))
            text = text.replace(it[0], tmp)
        return text

    def __read_text(self):
        with open(self._input_file, "r",encoding='utf-8') as fin:
            return fin.read()

    def __save_text(self, new_text):
        # 替换原来文本的名称, %filename%.offline.%suffix%
        old_name = os.path.basename(self._input_file)
        name_s = old_name.split(".")
        new_name = name_s[0]+".offline."+name_s[1]
        new_path = os.path.join(os.path.dirname(self._input_file), new_name)
        os.rename(self._input_file,new_path)
        with open(os.path.join(os.path.dirname(self._input_file), old_name), "w",encoding='utf-8') as fout:
            fout.write(new_text)

    def doit(self):
        self.__save_text(self.__replace_img_path())
        print("Done!")


if __name__ =="__main__":
    if len(sys.argv) < 2:
        print("请输入待转换 Markdown 路径")
    else:
        arg = sys.argv[1]
        if "--help" in arg:
            print("""
            1. 请在项目的 .gitignore 末尾添加 *.offline.md
            2. 命令行参数 填入需要转换的路径即可
            3. 修改此文件中的配置项，建议在每个项目中建一份这个文件，方便使用
            """)
        else:
            try:
            	Replacer(arg).doit()
            except:
        	    print("请输入正确文件路径或 --help ！")
