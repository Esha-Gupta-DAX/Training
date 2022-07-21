from django.shortcuts import render, redirect
from .models import todo
from .forms import todoForm

def todo_view(request):
    x = todo.objects.filter(title='New').values_list('itemId')

    if request.method == "POST":
        print(request)
        form = todo()
       
        print(request.POST.get('title'))
        form.title = request.POST.get('title')
        form.description = request.POST.get('descrip')
        print(form.title, form.description)
        # form.targeted_date = request.POST.get('targetdate')
        form.save()
        return redirect('todoapp:todolist')
    
    items = todo.objects.all().order_by('created_date')
    # print('items: ',items)
    return render(request,'todoapp/todo.html',{'items':items})


def deleteItem(request,itemId):
    itemObject = todo.objects.filter(itemId=itemId)
    itemObject.delete()
    items = todo.objects.all().order_by('created_date')
    
    return redirect('todoapp:todolist')

def update_view(request):
    items = todo.objects.all().order_by('created_date')
    return render(request,'todoapp/update.html',{'items':items})



def updateItem(request,itemId):
    
    itemObject = todo.objects.get(itemId = itemId)
    
    if request.method == "POST":
        itemObject.title = request.POST.get('title')
        itemObject.description = request.POST.get('descrip')
        itemObject.save()
        return redirect('todoapp:todolist')
    

    return render(request,'todoapp/updateForm.html',{'item' : itemObject})

def completedItem(request,itemId):
    itemObject = todo.objects.get(itemId = itemId)
    itemObject.status = True
    itemObject.save()

    items = todo.objects.all().order_by('created_date')

    return render(request,'todoapp/todo.html',{'items':items})
