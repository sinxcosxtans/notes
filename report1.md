#### 第九周学习报告

##### 一.盒子模型

###### 1. border边框

```css
border-width
```

```css
border-style:solid/dashed/dotted
```

```css
border-color
```

###### 2. padding内边距

```css
padding-left/right/top/bottom
```

padding影响实际盒子实际大小

###### 3. margin外边距

```css
margin-left/right/top/bottom
```

块级盒子水平居中：盒子指定宽度，左右外边距设为auto



##### 二.浮动

```css
float：none/right/left
```

######  清除浮动

```css
clear：both/right/left
```

- 额外标签法

- 给父级添加overflow属性

  ```css
  overflow: hidden/auto/scroll
  ```

- 父级after伪元素

- 父级双伪元素



##### 三.定位

定位=定位模式+边偏移

###### 1.静态定位

无定位（默认），无边偏移

```css
选择器 {position：static}
```

###### 2.相对定位

参照点为自身原来位置，仍然占有原来位置

```
选择器 {position：relative}
```

###### 3.绝对定位

![image-20221103084735131](C:\Users\summer\AppData\Roaming\Typora\typora-user-images\image-20221103084735131.png)

```
选择器 {position：absolute}
```

用于制作轮播图

![image-20221103085319858](C:\Users\summer\AppData\Roaming\Typora\typora-user-images\image-20221103085319858.png)

###### 4.固定定位

![image-20221103085832997](C:\Users\summer\AppData\Roaming\Typora\typora-user-images\image-20221103085832997.png)

```css
选择器 {position：fixed}
```

###### 5.粘性定位

![image-20221103093218474](C:\Users\summer\AppData\Roaming\Typora\typora-user-images\image-20221103093218474.png)

```css
 选择器 {position：sticky;
		top/left/right/bottom:  px;			
}
```



##### 四.元素显示隐藏

```css
display：none/block
```

```css
visibility:visible/hidden
```

```css
overflow:hidden
```



##### 五.精灵图

##### 六.字体图标的应用
