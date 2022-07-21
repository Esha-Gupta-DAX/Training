from django import forms 
from .models import todo

# creating a form
class todoForm(forms.Form):
    title = forms.CharField(max_length = 200)
    description = forms.CharField(widget=forms.Textarea)
    targeted_date = forms.DateField()


# class SaveData(forms.ModelForm):
#     class Meta:
#         model = todo
#         field = ('title','descrip')
