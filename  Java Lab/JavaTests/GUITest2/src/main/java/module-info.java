module com.example.guitest2 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;

    opens com.example.guitest2 to javafx.fxml;
    exports com.example.guitest2;
}