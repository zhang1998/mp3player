#!/bin/bash
echo  "输入你的commit"

read name #//从键盘输入

git add .
git commit -m "$name"
git push origin start_from_new_login
