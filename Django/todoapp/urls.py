from django.urls import path, include
from . import views
app_name="todoapp"
urlpatterns = [

    path('',views.todo_view,name='todolist'),
    path('todolist',views.todo_view,name='todolist'),
    path('delete/<int:itemId>',views.deleteItem,name="deleteItem"),
    path('update',views.update_view,name="update"),
    path('update/<int:itemId>',views.updateItem,name="updateItem"),
    path('completed/<int:itemId>',views.completedItem,name="completedItem"),
]