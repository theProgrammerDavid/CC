### Java Fx

- On newer versions of ubuntu, `JavaFX` is distributed separately from the `JDK`.

  ```bash
  sudo apt install openjfx
  ```

- Once you have that installed, you need to specify the runtime modules for OpenJFX by adding these to your command to compile

  ```bash
  --module-path /usr/share/openjfx/lib --add-modules=javafx.base,javafx.controls,javafx.fxml,javafx.graphics,javafx.media,javafx.swing,javafx.web
  ```

- Your commands to compile and run will now look like

  ```bash
  javac --module-path /usr/share/openjfx/lib --add-modules=javafx.base,javafx.controls,javafx.fxml,javafx.graphics,javafx.media,javafx.swing,javafx.web q1.java


  java --module-path /usr/share/openjfx/lib --add-modules=javafx.base,javafx.controls,javafx.fxml,javafx.graphics,javafx.media,javafx.swing,javafx.web q1
  ```

- All `JavaFx` programs have a class that `extends` `javafx.application.Application`

​```java
import javafx.application.Application;
import javafx.stage.Stage;
public class demo extends Application{
    public static void main(String args[]){

    }
    @Override
    public void start(Stage primaryStage)throws Exception
}
  ```

- Every `JavaFx` application has the following components :

  - Stage
  - Layout
  - Scene
  - Control
  - Events

- Sample Program

  ```java
  import javafx.application.Application;
  import javafx.stage.Stage;
  import javafx.scene.control.*; //Button
  import javafx.scene.layout.*; // HBox
  import javafx.scene.*; //Scene
  
  public class demo1 extends Application {
      public static void main(String[] args) {
          launch();
      }
  
      @Override
      public void start(Stage primaryStage) throws Exception{
          Button b = new Button("Click Me");
  
          HBox hb = new HBox();
  
          hb.getChildren().add(b);
          Scene s = new Scene(hb);
          primaryStage.setScene(s);
          primaryStage.show();
      }
  }
  ```

| Function Available                  |
| :---------------------------------- |
| _primaryStage_.show();              |
| _primaryStage_.setScene(val);       |
| _primaryStage_.setTitle(val);       |
| _primaryStage_.getTitle();          |
| _primaryStage_.setWidth(val);       |
| _primaryStage_.setHeight(val);      |
| _primaryStage_.getWidth();          |
| _primaryStage_.getHeight();         |
| _primaryStage_.setFullScreen(true); |
| _primaryStage_.isFullScreen();      |
| _primaryStage_.close();             |

- Layouts

  - Can be flexible layouts or dynamic layouts

  - `HBox`, `VBox`, `StackPane`, `FlowPane`, `GridPane`, `BorderPane`

    - | Layout     | Description                                                                                                                |
      | ---------- | -------------------------------------------------------------------------------------------------------------------------- |
      | HBox       | arranges its content nodes horizontally in a single row                                                                    |
      | VBox       | arranges its content nodes vertically in a single column                                                                   |
      | StackPane  | places the content nodes in a back-to-front single stack                                                                   |
      | FlowPane   | arranges its content nodes in either a horizontal or vertical "flow", wrapping at the specified width or height boundaries |
      | GridPane   | Flexible grid of rows and columns in which to lay out content nodes                                                        |
      | BorderPane | lays out its content nodes in the top, bottom, right, left or centre region                                                |

  - `ListView`

    ```java
    ListView<String> lv = new ListView<String>();
    lv.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
    lv.getItems().add("English");
    lv.getItems().add("Physics");
    lv.getItems().add("Java");
    lv.getItems().add("DBMS");
    ```

  - `DatePicker`
    ```java
    DatePicker d = new DatePicker();
    ```
  - `Label`

    ```java
    import javafx.scene.control.Label;
    import javafx.scene.paint.Color;
    import javafx.scene.text.TextAlignment;


    Label l = new Label("test");
    l.setTextFill(Color.RED);
    l.setText("hello");
    l.setWrapText(true);
    l.setFont(new Font("Times New Roman", 32));
    l.setTextAlignment(TextAlignment.CENTER);
    // LEFT, CENTER, RIGHT, JUSTIFY


    // adding a picture to the label
    FileInputStream fin = new FileInputStream("/path/to/pic");
            Image img = new Image(fin);
            ImageView iv = new ImageView(img);
            Label l = new Label("Hello World", iv);
    ```

  - `Button `

    ```java
    import javafx.scene.control.Button;

    Button b = new Button();
    b.setText("Hello World");
    b.setDisable(true);
    b.setWrapText(true);
    ```

  - `Radio Button`

    ```java
    import javafx.scene.control.RadioButton;

    ToggleGroup tg = new ToggleGroup();

    RadioButton opt1 = new RadioButton("English");
    RadioButton opt2 = new RadioButton("Chemistry");
    RadioButton opt3 = new RadioButton("French");

    opt1.setToggleGroup(tg);
    opt2.setToggleGroup(tg);
    opt3.setToggleGroup(tg);
    ```

  - `CheckBox`

    ```java
    import javafx.scene.control.CheckBox;

    //same as RadioButton
    ```

  - `HyperLink`

    ```java
    import javafx.scene.control.Hyperlink;
    HyperLink link1 = new HyperLink("http://something.com");
    ```

- GridPane

  ```java
    GridPane grid = new GridPane();
    grid.addRow(6, errorLabel);
    
    grid.add(textFieldLabel, 0, 0);
  // component, column, row
    
    grid.setHgap(10);
    grid.setVgap(10);
  ```

  

  - `ComboBox`

    ```java
    import javafx.scene.control.ComboBox;
    
    ComboBox<String> stuff = new ComboBox<String>();
    stuff.getItems().add("English");
    stuff.getItems().add("Physics");
    ```

#### Events in Java

Java has a wide variety of events, most common of which are `ActionEvent`

```java
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
```

We define an action event callback as follows :

```java
EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() {

            public void handle(ActionEvent e) {
                System.out.println("Hello World");
            }
        };
```

We then call our `JavaFx` object and register this callback

```java
Button btn = new Button("Click Me") ;
btn.setOnAction(event);
```
