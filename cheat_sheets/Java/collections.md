### Java Collections

- Custom Sorter

  ```java
  class MobilePhone {
      public String ModelName;
      public String BrandName;
      public String ModelNumber;
      public double price;
      public int quantity;
  
      public MobilePhone(String Model, String BrandName, String ModelNum, int quantity, double price) {
          this.ModelName = Model;
          this.BrandName = BrandName;
          this.ModelName = ModelNum;
          this.quantity = quantity;
          this.price = price;
      }
  
  }
  
  class CustomComparator implements Comparator<MobilePhone> {
      @Override
      public int compare(MobilePhone o1, MobilePhone o2) {
          return o1.quantity < o2.quantity ? 1 : -1;
      }
  }
  
  ...
      ArrayList<MobilePhone> objectsList = new ArrayList<>();
      Collections.sort(objectsList, new CustomComparator());
  
  
  ```

  

- Iterate through a collection

  **For loop**

  ```java
  LinkedList<String> linkedList = new LinkedList<>();
  System.out.println("==> For Loop Example.");
  for (int i = 0; i < linkedList.size(); i++) {
      System.out.println(linkedList.get(i));
  }
  ```

  **Enhanced for loop**

  ```java
  for (String temp : linkedList) {
      System.out.println(temp);
  }
  ```

  **While loop**

  ```java
  int i = 0;
  while (i < linkedList.size()) {
      System.out.println(linkedList.get(i));
      i++;
  }
  ```

  **Iterator** 

  ```java
  Iterator<String> iterator = linkedList.iterator();
  while (iterator.hasNext()) {
      System.out.println(iterator.next()); 
  }
  ```