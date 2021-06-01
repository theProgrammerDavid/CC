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

  

