# Console Graphics

Console graphics is a library used to develop user interface on windows terminal environment.
The Library consist of the following components: Label, Button, TextBox, NumericBox, ComboBox, CheckList, RadioBox, MessageBox and Panel.

## Components Overview

### Label
![label](https://user-images.githubusercontent.com/12692788/42876364-1b81d642-8a8f-11e8-8d15-cd417e9d923c.png)

**Usage Example:**
```
Label mainPanelLabel(65, 1, "Main Panel");
mainPanelLabel.setColor(Color::Red, Color::Green);
```
### Button
![button](https://user-images.githubusercontent.com/12692788/42877000-02912906-8a91-11e8-92ab-8b4518da3ba5.png)

**Usage Example:**
```
Button btn3(1, 26, 31, { 8,2 }, "Button3");
btn3.setColor(Color::White, Color::Green);
```
### TextBox
![textbox](https://user-images.githubusercontent.com/12692788/42877643-08132ca6-8a93-11e8-8151-ec9b25c1e7e3.png)

**Usage Example:**
```
TextBox t(1, 4, 21, { 15,3 });
t.setColor(Color::Purple, Color::White);
```
### NumericBox
![numericbox](https://user-images.githubusercontent.com/12692788/42877983-226c4190-8a94-11e8-9484-f627d2ddef36.png)

**Usage Example:**
```
NumericBox n(1, 50, 21, { 15,3 }, 5);
n.setColor(Color::Red, Color::Blue);
```
### ComboBox
![combobox](https://user-images.githubusercontent.com/12692788/42878462-c6b45340-8a95-11e8-8722-32402ca756d5.png)

**Usage Example:**
```
ComboBox cb(1, 82, 8, { 10,2 }, { "one","two","three" });
cb.setColor(Color::Cyan, Color::Purple);
```
### CheckList
![checklist](https://user-images.githubusercontent.com/12692788/42878917-68ac8a90-8a97-11e8-9d71-f0347cbd3083.png)

**Usage Example:**
```
CheckList cc(1, 4, 4, { 15,10 }, { "one","two","three" });
cc.setColor(Color::Green, Color::White);
```

### RadioBox
![radiobox](https://user-images.githubusercontent.com/12692788/42879123-373c967a-8a98-11e8-98fc-8a0c67f61458.png)

**Usage Example:**
```
RadioBox rc(1, 45, 4, { 18,10 }, { "optionOne","optionTwo","optionThree" });
rc.setColor(Color::Blue, Color::White);
```
### MessageBox
![messagebox](https://user-images.githubusercontent.com/12692788/42879335-eb4b56b0-8a98-11e8-91a8-ceddf10d5b3a.png)

**Usage Example:**
```
Message_Box mb(1, 82, 18, { 30,8 }, "This is a message box!!!");
mb.setColor(Color::White, Color::Blue);
```
### Panel
![panel](https://user-images.githubusercontent.com/12692788/42879550-b84a4446-8a99-11e8-9658-00d6dcb8361f.png)

**Usage Example:**
```
Panel p(2, 0, 0, { 80,20 });

Label mainPanelLabel(36, 1, "Main Panel");
mainPanelLabel.setColor(Color::Red, Color::Green);
p.Add(&mainPanelLabel);

Label checkListLabel(15, 3, "CheckList");
checkListLabel.setColor(Color::Green, Color::White);
p.Add(&checkListLabel);

CheckList cc(1, 4, 4, { 30,14 }, { "one","two","three" });
cc.setColor(Color::Green, Color::White);
p.Add(&cc);

Label radioBoxLabel(55, 3, "RadioBox");
radioBoxLabel.setColor(Color::Cyan, Color::Purple);
p.Add(&radioBoxLabel);

RadioBox rc(1, 45, 4, { 30,14 }, { "optionOne","optionTwo","optionThree" });
rc.setColor(Color::Blue, Color::Orange);
p.Add(&rc);
```
**Image:**

![panelimage](https://user-images.githubusercontent.com/12692788/42879935-0de7d6ce-8a9b-11e8-8324-245e67ca7ded.png)

## Course Information
**Course Name:** Software Engineering Methods

**Head Lecturer & Tutor** 
* Dr. Amit Resh
* Asaf Algawi

**Contributors**
* [Hanan Avraham](https://github.com/hananavraham) 
* [Leon Benjamin](https://github.com/leonben2892) 
* [Matan Nabatian](https://github.com/matanabatian) 
* [Yarin Hala](https://github.com/YarinHala) 
